#include "../Driver/digits_driver.c"
#include "../Driver/keyboard_driver.c"
#include "../Driver/led_driver.c"
#include "../Driver/switch_driver.c"

// From low to high, turn on four lights at a time
int main(){
int key1;
int key2;
int delay;
int delayer=20000;

delay=delayer;
key1=0x0000000f;
key2=0x00000000;
while(delay>=0){
    light_leds(key1,key2);
    delay=delay-1;
};

delay=delayer;
key1=0x000000f0;
key2=0x00000000;
while(delay>=0){
    light_leds(key1,key2);
    delay=delay-1;
};

delay=delayer;
key1=0x00000f00;
key2=0x00000000;
while(delay>=0){
    light_leds(key1,key2);
    delay=delay-1;
};

delay=delayer;
key1=0x00000000;
key2=0x0000000f;
while(delay>=0){
    light_leds(key1,key2);
    delay=delay-1;
};

delay=delayer;
key1=0x00000000;
key2=0x000000f0;
while(delay>=0){
    light_leds(key1,key2);
    delay=delay-1;
};

delay=delayer;
key1=0x00000000;
key2=0x00000f00;
while(delay>=0){
    light_leds(key1,key2);
    delay=delay-1;
};

return 0;
}