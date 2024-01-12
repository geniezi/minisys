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

S : program { }
  ;
program : stmts	{backpatch($1.nextlist,"LABEL_"+ gen(nextInstr));}
	;
stmts	: stmts	M stmt { backpatch($1.nextlist, $2.instr); $$.nextlist = $3.nextlist;}
	| stmt { backpatch($1.nextlist, "LABEL_"+ gen(nextInstr));}
	;
stmt	: includestmt {}
	| '{' stmts  '}' { $$.nextlist = $2.nextlist; }
	| fun_define  {	emit("nop","","",""); returnToGlobalTable(); $$.nextlist = $1.nextlist; }
	| if_stmt { $$.nextlist = $1.nextlist; }
	| while_stmt { $$.nextlist = $1.nextlist; }
	| var_decl ';' { $$.nextlist = $1.nextlist; }
	| 'static' var_decl ';' { $$.nextlist = $2.nextlist; }
	| expr_stmt ';' {$$.nextlist = $1.nextlist;}
	| 'return' expr ';' { emit("return",$2.place,"",""); }
	| 'return' ';' { emit("return","","",""); }
	| call_stmt ';' {$$.nextlist = $1.nextlist; }
	| 'set_mem' '(' expr ',' expr ')' ';' { emit("set",$3.place,$5.place,""); }
	| ';' { }
	;
includestmt : 'include' '"' 'filename' '"' { filelist.push_back($3.lexeme); }
			| 'include' '<' 'filename' '>' { filelist.push_back($3.lexeme); }
			;
fun_define   : fun_decl_head BlockLeader '{' stmts '}' { $$.name = $1.name; $$.nextlist=$4.nextlist; } 
			;
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
      | type_spec 'id' '[' 'num' ']' {
			$$.itemlist = makeParam($2.lexeme,make_array(atoi($4.lexeme.c_str()),$1.type),atoi($4.lexeme.c_str()) * $1.width); 
			}
      ;
var_decl : type_spec 'id' {enter($2.lexeme,$1.type,$1.width); }
	| type_spec 'id' '=' expr {
		p = enter($2.lexeme,$1.type,$1.width); 
		emit("MOV",$4.place,"",p); 
		}
	| type_spec 'id' '[' 'num' ']' {
		enter($2.lexeme,make_array(atoi($4.lexeme.c_str()),$1.type),atoi($4.lexeme.c_str()) * $1.width); 
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
			emit("MOV",$3.place,"",p); 
			}
		  | 'id' '[' expr ']' '=' expr {
			{
				string ty=getType($1.lexeme);
				if(ty.find("array")==ty.npos) error(ty+"cannot be converted to array");
				emit("MOVaddr",lookupPlace($1.lexeme),$3.place,"");
				emit("MOVoff","",$6.place,lookupPlace($1.lexeme));
			}
			}
		  ;
expr : expr '+' expr {
                	$$.place = newtemp($1.place);
			emit("add", $1.place, $3.place, $$.place);
                     }
     | expr '-' expr {
                	$$.place = newtemp($1.place);
			emit("sub", $1.place, $3.place, $$.place);
                     }
     | expr '*' expr {
                	$$.place = newtemp($1.place);
			emit("mul", $1.place, $3.place, $$.place);
                     }
     | expr '/' expr {
                	$$.place = newtemp($1.place);
			emit("div", $1.place, $3.place, $$.place);
                     }
     | expr '%' expr {
                	$$.place = newtemp($1.place);
			emit("rem", $1.place, $3.place, $$.place);
                     }
     | expr '&' expr {
                	$$.place = newtemp($1.place);
			emit("and", $1.place, $3.place, $$.place);
                     }
     | expr '|' expr {
                	$$.place = newtemp($1.place);
			emit("or", $1.place, $3.place, $$.place);			
                     }
     | expr '^' expr {
                	$$.place = newtemp($1.place);
			emit("xor", $1.place, $3.place, $$.place);
                     }
     | expr '>>' expr {
                	$$.place = newtemp($1.place);
			emit("srl", $1.place, $3.place, $$.place);
                      }
     | expr '<<' expr {
                	$$.place = newtemp($1.place);
			emit("sll", $1.place, $3.place, $$.place);
                      }
     | '(' expr ')'  {
                	$$.place = $2.place;
                     }
     | 'id'   	     {
			$$.place = lookupPlace($1.lexeme);
            	     }
     | call_stmt {
			if($1.type=="void") error("void value not ignored as it ought to be");
			$$.place = newtemp($1.place);
			emit("MOV",$1.place,"",$$.place); 
			}
     | 'num' {
		$$.place = addNum($1.lexeme);
	     }
	| '-' expr {
		$$.place = newtemp($2.place);
		emit("neg",$2.place,"",$$.place);
	}
	| 'id' '[' expr ']' {
		{
			string ty=getType($1.lexeme);
			if(ty.find("array")==ty.npos) error(ty+"cannot be converted to array");
			int p1=ty.find('<');
			int p2=ty.find(',');
			$$.place = newtemp(ty.substr(p1+1,p2-p1-1));
			emit("MOVaddr",lookupPlace($1.lexeme)	,$3.place,"");
			emit("MOVoff",$$.place,"",lookupPlace($1.lexeme));
		}
	}	
	| 'load_mem' '(' expr ')' {
		$$.place = newtemp("int");
		emit("load",$3.place,"",$$.place);
	}
     ;
arg_list  : arg_list ',' expr { paramStack.push($3.place); }
          |  expr  { paramStack.push($1.place);	}
	  | { }
	  ;
call_stmt : 'id' '(' arg_list ')' {
		{
			p = gen(paramStack.size());
			while (!paramStack.empty()) {
				emit("param", paramStack.top(),"","");
				paramStack.pop();
			}
			$$.type=getRetType($1.lexeme);
			emit("call", p, $1.lexeme,"");
			if($$.type!="void")
			{
				enter("#","int",4);
				$$.place=newtemp($$.type);
				emit("MOV","#","",$$.place);
			}
		}	
	}
	;
if_stmt : 'if' '(' logic_expr ')' M stmt {
							backpatch($3.truelist, $5.instr);
							$$.nextlist = merge($3.falselist, $6.nextlist);
						     }
	| 'if' '(' logic_expr ')' M stmt N 'else' M stmt {
									backpatch($3.truelist, $5.instr);
									backpatch($3.falselist, $9.instr);
									$$.nextlist = merge(merge($6.nextlist, $7.instr), $10.nextlist);
								     }
	;
while_stmt : 'while' M '(' logic_expr ')' M stmt {
								backpatch($7.nextlist, $2.instr);
								backpatch($4.truelist, $6.instr);
								$$.nextlist = $4.falselist;
								emit("j","","",$2.instr);
								addToLabel($2.instr);
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
				addNum("0");
				emit("j!=", $1.place, "0", "_");
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
    | '>='{$$.op = ">=";}
    | '=='{$$.op = "==";}
    | '!='{$$.op = "!=";}
    ;