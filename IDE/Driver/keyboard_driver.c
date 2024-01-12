// read 4x4 keyboard (query method)
int read_keyboard() {
  // key in 0 - F
  int key;
  key =load_mem(0xFFFFFC10);
  return key;
}

void clear_keyboard(){
  // $0xFFFFFC10 = 0xFFFFFFFF;
  set_mem(0xFFFFFC10,0xFFFFFFFF);
  return;
}