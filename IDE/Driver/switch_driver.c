int read_switch() {
    int a;
    // a = $0xFFFFFC70;
    a=load_mem(0xFFFFFC70);
    return a;
}