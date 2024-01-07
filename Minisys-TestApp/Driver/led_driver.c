// light leds according to code
void light_leds(int code1,int code2) {
  // only low 24 bits is valid
  // $0xFFFFFC60 = code1;
  // $0xFFFFFC62 = code2;
  set_mem($0xFFFFFC60,code1)
  set_mem($0xFFFFFC62,code2)
  return;
}