/*=================================================== GENERAL FUNCTION =========*/
// Membuat Fungsi MAP untuk mengatur nilai Minimal & Maksimal (Re-scale)
float floatMap(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

/*=================================================== MENU FUNCTION =========*/
//gui_ = artinya ini fungsi display

void gui_cursorpos(char y){
  lcd.setCursor(0,y);
  lcd.print(">");
}

void gui_runPage(int page){
  switch(page){
    case 11:
      if(state_relay==0){
        lcd_putsxy(0,1, "OFF   ");
      }
      else if(state_relay==1){
        lcd_putsxy(0,1, "ON   ");
      }
      cont_relay(state_relay);
    break;

    case 21:
      if (read_PIR()==0){
        lcd_putsxy(0,1, "                 "); 
        lcd_putsxy(0,1, "Undetected     "); 
      } 
      else {
        lcd_putsxy(0,1, "               ");     
        lcd_putsxy(0,1, "Detected      ");     
      }
    break;

    case 12:
      lcd_putsxy(7,1, String(read_us()) + " CM");
    break; 

    case 22:
      if(state_led==0){
        cont_led_on_off(led_delay);
      }
      else if(state_led==1){
        cont_led_running(led_delay);
      }
    break;

    case 13:
      read_rfid();
    break;

    case 23:
      if(state_rgb==0){
        rgb_contrast(rgb_delay);
      }
      else if(state_rgb==1){
        rgb_dimming(rgb_delay);
      }
      else if(state_rgb==2){
        rgb_aurora(rgb_delay);
      }
    break;

    case 14:
      read_keypad();
    break;

    case 24:
      lcd_putsxy(4,1, String(read_D0soil()));
      lcd_putsxy(11,1, String(read_A0soil()));
    break;

    case 15:
      if(read_flame()==1){
        lcd_putsxy(0,1, "Undetected ");
      }
      else if(read_flame()==0){
        lcd_putsxy(0,1, "Detected   ");
      }
    break;

    case 25:
      lcd_putsxy(5,1, String(read_pot(),0));
      lcd_putsxy(11,1, String(read_potpercent(),1) + " %");
    break;

    case 16:
      now = DS1307_RTC.now();

      lcd_putsxy(6,0, String(now.day()) + "/");
      lcd_putsxy(9,0, String(now.month()) + "/");
      lcd_putsxy(12,0, String(now.year()));

      lcd_putsxy(0,1, String(now.hour()) + ":");
      lcd_putsxy(3,1, String(now.minute()) + ":");
      lcd_putsxy(6,1, String(now.second()));

      lcd_putsxy(9,1, Week_days[now.dayOfTheWeek()]);
    break;

    case 26:
      oled_putimg();
    break;

    case 17:
      // lcd_putsxy(3,1, String(read_D0gas()));
      // lcd_putsxy(9,1, String(read_A0gas()));
    break;

    case 27:
      // lcd_putsxy(3,1, String(read_D0rain()));
      // lcd_putsxy(9,1, String(read_A0rain()));
    break;

    case 18:
      lcd_putsxy(3,1, String(buzz_on));
      lcd_putsxy(12,1, String(buzz_off));
      cont_buzzer(buzz_on, buzz_off);
    break;
    case 28:
      cont_servo(servo_sudut);
    break;

    case 19:
      read_dht_to_lcd();
    break;
  }
}