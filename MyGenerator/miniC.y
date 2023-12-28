%right '=' '+=' '-=' '*=' '/=' '%='
%left '||'
%left '&&'
%left '|'
%left '^'
%left '&'
%left '==' '!='
%left '<' '>' '<=' '>='
%left '<<' '>>' 
%left '+' '-'
%left '*' '/' '%'
%right '!'
%left 'else'
%%

S : program {}
  ;
program : stmts	{}
	;
stmts	: stmts	M stmt { backpatch($1.nextlist, $2.instr); $$.nextlist = $3.nextlist;}
	| stmt { $$.nextlist = $1.nextlist; }
	;
stmt	: '{' stmts  '}' { $$.nextlist = $2.nextlist; }
	| fun_define  {	returnToGlobalTable(); }
	| if_stmt { $$.nextlist = $1.nextlist; }
	| while_stmt { $$.nextlist = $1.nextlist; }
	| var_decl ';' { $$.nextlist = $1.nextlist; }
	| static var_decl ';' { $$.nextlist = $2.nextlist; }
	| expr_stmt ';' {}
	| 'return' expr ';' { emit("return",$2.place,"",""); setOutLiveVar($2.place); }
	;
fun_define   : fun_decl_head BlockLeader '{' stmts '}' { $$.name = $1.name; } ;
fun_decl_head : type_spec 'id' '(' ')' { $$.name = $2.lexeme; 
					 createSymbolTable($2.lexeme, $1.width); 
					 addFunLabel(nextInstr, $2.lexeme);}
	      | type_spec 'id' '(' param_list ')' { 
			$$.name = $2.lexeme; 
			createSymbolTable($2.lexeme, $1.width); 
			addToSymbolTable($4.itemlist); 
			addFunLabel(nextInstr, $2.lexeme);}
	      ;
param_list : param_list ',' param { $$.itemlist = $1.itemlist || $3.itemlist; }
	   | param { $$.itemlist = $1.itemlist; }
	   ;
param : type_spec 'id' { $$.itemlist = makeParam($2.lexeme,$1.type,$1.width); }
      | type_spec 'id' '[' num ']' {
			$$.itemlist = makeParam($2.lexeme,make_array($4.lexval,$1.type),$4.lexval * $1.width); 
			}
      ;
var_decl : type_spec 'id' {enter($2.lexeme,$1.type,$1.width); }
	| type_spec 'id' '=' expr {
		p = enter($2.lexeme,$1.type,$1.width); 
		emit("MOV",$4.place,"",p); 
		}
	| type_spec 'id' '[' num ']' {
		enter($2.lexeme,make_array($4.lexval,$1.type),$4.lexval * $1.width); 
	}
	;
type_spec : 'int' { $$.type = "int";
		    $$.width = "4";
		   }
		| 'double' {	$$.type = "double";
			$$.width = "8";
		      }
		| 'void' { $$.type = "void";
		    $$.width = "0";
		    }
		| 'char' { $$.type = "char";
		    $$.width = "1";
		    }
        | 'bool' { $$.type = "bool";
		    $$.width = "1";
		    }
		| 'float' { $$.type = "float";
		    $$.width = "4";
		    }
		;
expr_stmt : 'id' '=' expr { 
		p = lookupPlace($1.lexeme); 
		if (p.empty()) error("undefined variable used"); 
		emit("MOV",$3.place,"",p); };
expr : expr '+' expr {
                	$$.place = newtemp($1.place);
			emit("add", $1.place, $3.place, $$.place);
			$$.lexval = $1.lexval + $3.lexval;
                     }
     | expr '-' expr {
                	$$.place = newtemp($1.place);
			emit("sub", $1.place, $3.place, $$.place);
			$$.lexval = $1.lexval - $3.lexval;
                     }
     | expr '*' expr {
                	$$.place = newtemp($1.place);
			emit("mul", $1.place, $3.place, $$.place);
			$$.lexval = $1.lexval * $3.lexval;
                     }
     | expr '/' expr {
                	$$.place = newtemp($1.place);
			emit("div", $1.place, $3.place, $$.place);
                     }
     | expr '%' expr {
                	$$.place = newtemp($1.place);
			emit("rem", $1.place, $3.place, $$.place);
			$$.lexval = $1.lexval % $3.lexval;
                     }
     | expr '&' expr {
                	$$.place = newtemp($1.place);
			emit("and", $1.place, $3.place, $$.place);
			$$.lexval = $1.lexval & $3.lexval;
                     }
     | expr '|' expr {
                	$$.place = newtemp($1.place);
			emit("or", $1.place, $3.place, $$.place);
			$$.lexval = $1.lexval | $3.lexval;
                     }
     | expr '^' expr {
                	$$.place = newtemp($1.place);
			emit("xor", $1.place, $3.place, $$.place);
			$$.lexval = $1.lexval ^ $3.lexval;
                     }
     | expr '>>' expr {
                	$$.place = newtemp($1.place);
			emit("srl", $1.place, $3.place, $$.place);
			$$.lexval = $1.lexval >> $3.lexval;
                      }
     | expr '<<' expr {
                	$$.place = newtemp($1.place);
			emit("sll", $1.place, $3.place, $$.place);
			$$.lexval = $1.lexval << $3.lexval;
                      }
     | '(' expr ')'  {
                	$$.place = $2.place;
					$$.lexval = $2.lexval;
                     }
     | 'id'   	     {
			$$.place = lookupPlace($1.lexeme);
            	     }
     | 'id' '(' arg_list ')' {
				p = gen(paramStack.size());
				while (!paramStack.empty()) {
				    emit("param", paramStack.top(),"","");
				    paramStack.pop();
			        }
				emit("call", p, $1.lexeme,"");
				enter("#","int",4);
				$$.place = newtemp("#");
				emit("MOV","#","",$$.place); }
     | 'num' {
		$$.place = addNum($1.lexeme);
		$$.lexval = $1.lexeme;
	     }
	| '-' 'num' {
		$$.place = addNum($2.lexeme);
		$$.lexval = - $2.lexeme;
	}
	| 'id' '[' expr ']' {
		{
			string ty=getType($$.lexeme);
			if(ty.substr(0,6)!="array<") error(ty+"cannot be converted to array");
			int p=$1.place.find('(');
			$$.place = to_string(atoi($1.place.substr(0,p)) + $1.width * $3.lexval)+"(x8)";
		}
	}	
     ;
arg_list  : arg_list ',' expr { paramStack.push($3.place); }
          |  expr  { paramStack.push($1.place);	}
	  | { }
	  ;
if_stmt : 'if' BlockLeader '(' logic_expr ')' M stmt {
							backpatch($4.truelist, $6.instr);
							$$.nextlist = merge($4.falselist, $7.nextlist);
						     }
	| 'if' BlockLeader '(' logic_expr ')' M stmt N 'else' M stmt {
									backpatch($4.truelist, $6.instr);
									backpatch($4.falselist, $10.instr);
									$$.nextlist = merge(merge($7.nextlist, $8.instr), $11.nextlist);
								     }
	;
while_stmt : 'while' BlockLeader M '(' logic_expr ')' M stmt {
								backpatch($8.nextlist, $3.instr);
								backpatch($5.truelist, $7.instr);
								$$.nextlist = $5.falselist;
								emit("j","","",$3.instr);
							     }
	   ;
logic_expr	: logic_expr '&&' M logic_expr {
				backpatch($1.truelist, $3.instr);
				$$.truelist = $4.truelist;
				$$.falselist = merge($1.falselist, $4.falselist);
			}	
		| logic_expr '||' M logic_expr {
				backpatch($1.falselist, $3.instr);
				$$.truelist = merge($1.truelist, $4.truelist);
				$$.falselist = $4.falselist;
			}
		| '!' logic_expr {
				$$.truelist = $2.falselist;
				$$.falselist = $2.truelist;
			}
		| '(' logic_expr ')' {
				$$.truelist = $2.truelist;
				$$.falselist = $2.falselist;
			}
		| expr rel expr {
				$$.truelist = makelist(nextInstr);
				$$.falselist = makelist(nextInstr+1);
				emit("j"+$2.op, $1.place, $3.place, "_");
				emit("j","","","_");
			}
		| expr { 
				$$.truelist = makelist(nextInstr);
				$$.falselist = makelist(nextInstr+1);
				emit("j!=", $1.addr, "0", "_");
				emit("j","","","_");
			}
		| 'true' {
				$$.truelist = makelist(nextInstr);
				emit("j","","","_");
			}
		| 'false' {
				$$.falselist = makelist(nextInstr);
				emit("j","","","_");
			}
		;
M : {$$.instr = "LABEL_" + gen(nextInstr);}
  ;
N : { $$.instr = makelist(nextInstr);
      emit("j","","","_");}
  ;
BlockLeader : {
      addLeader(nextInstr);
    }
  ;
rel : '<' {$$.op = "<";}
    | '>' {$$.op = ">";}
    | '<='{$$.op = "<=";}
    | '<='{$$.op = ">=";}
    | '=='{$$.op = "==";}
    | '!='{$$.op = "!=";}
    ;