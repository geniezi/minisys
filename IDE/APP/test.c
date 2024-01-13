int WATCHDOG_ADDR = 0xfffffc50;
int SWITCH_ADDR = -0x390;
int LED_ADDR = -0x3a0;
int TIMER_ADDR = 0xfffffc20;
int KEYBOARD_ADDR = 0xfffffc10;
int BUZZER_ADDR = 0xfffffc40;
int PWM_ADDR = 0xfffffc30;
int Do = 0x12a2f;
int Rai = 0x109bb;
int Mi = 0xecbe;
int Fa = 0xdfda;
int Sao = 0xc74c;
int La = 0xb18e;
int Xi = 0x9e25;
int main(){
    int counter = 0;
    while(counter < 125000){
      counter = counter + 1;
      set_mem(WATCHDOG_ADDR,1);
    }
    set_mem(TIMER_ADDR,0);
    set_mem(TIMER_ADDR + 4,0xffff);
    while(true){
    set_mem(WATCHDOG_ADDR,1);
    int led_out;
    led_out = load_mem(SWITCH_ADDR);
    set_mem(LED_ADDR,led_out);
    int keyboard_state;
    int keyboard_value;
    keyboard_state = load_mem(KEYBOARD_ADDR + 2);
    set_mem(PWM_ADDR,0xf000);
    if(keyboard_state == 1){
        keyboard_value = load_mem(KEYBOARD_ADDR);
        if(keyboard_value == 1){
        set_mem(BUZZER_ADDR+2,1);
        set_mem(BUZZER_ADDR,Do);
        set_mem(PWM_ADDR + 2,0x1000);
        set_mem(PWM_ADDR + 4,1);
        }
        if(keyboard_value == 2){
        set_mem(BUZZER_ADDR+2,1);
        set_mem(BUZZER_ADDR,Rai);
        set_mem(PWM_ADDR + 2,0x2000);
        set_mem(PWM_ADDR + 4,1);
        }
        if(keyboard_value == 3){
        set_mem(BUZZER_ADDR+2,1);
        set_mem(BUZZER_ADDR,Mi);
        set_mem(PWM_ADDR + 2,0x3000);
        set_mem(PWM_ADDR + 4,1);
        }
        if(keyboard_value == 4){
        set_mem(BUZZER_ADDR+2,1);
        set_mem(BUZZER_ADDR,Fa);
        set_mem(PWM_ADDR + 2,0x4000);
        set_mem(PWM_ADDR + 4,1);
        }
        if(keyboard_value == 5){
        set_mem(BUZZER_ADDR+2,1);
        set_mem(BUZZER_ADDR,Sao);
        set_mem(PWM_ADDR + 2,0x5000);
        set_mem(PWM_ADDR + 4,1);
        }
        if(keyboard_value == 6){
        set_mem(BUZZER_ADDR+2,1);
        set_mem(BUZZER_ADDR,La);
        set_mem(PWM_ADDR + 2,0x6000);
        set_mem(PWM_ADDR + 4,1);
        }
        if(keyboard_value == 7){
        set_mem(BUZZER_ADDR+2,1);
        set_mem(BUZZER_ADDR,Xi);
        set_mem(PWM_ADDR + 2,0x7000);
        set_mem(PWM_ADDR + 4,1);
        }
    }
  }
}