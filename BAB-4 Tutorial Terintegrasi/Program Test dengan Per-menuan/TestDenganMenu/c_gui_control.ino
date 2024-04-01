// Variable GUI
int gui_pageNow=0;
int gui_menuSelect=3;

void gui_cur_erase(){
  lcd_erase(0, 0);
  lcd_erase(0, 1);
}

void gui_control(){
  switch(gui_pageNow){
    case 0:
      gui_changePage();
      gui_cursorpos(gui_menuSelect);
      break;

    case 99:
    if(btn_trig[4]==pressed){
      gui_pageNow=1; gui_changePage(); gui_menuSelect=0; gui_cursorpos(gui_menuSelect);
    }
    break;

    case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9:
      if(btn_trig[2]==pressed){
        gui_menuSelect++; gui_cur_erase();
        if(gui_menuSelect>1){
          gui_menuSelect=0;
          gui_pageNow++; 
          if(gui_pageNow>9){
            gui_pageNow=1;
          }
          gui_changePage();
          gui_cursorpos(gui_menuSelect);
        }
        else{gui_cursorpos(gui_menuSelect);}
      }
      else if(btn_trig[1]==pressed){
        gui_menuSelect--; gui_cur_erase();
        if(gui_menuSelect<0){
          gui_menuSelect=1;
          gui_pageNow--;
          if(gui_pageNow<1){
            gui_pageNow=9;
          }
          gui_changePage();
          gui_cursorpos(gui_menuSelect);
        }
        else{gui_cursorpos(gui_menuSelect);}
      }
      if(btn_trig[4]==pressed){
        if(gui_menuSelect==0){
          gui_menuSelect=1;
          gui_pageNow+=10;
          gui_changePage(); 
        }
        else if(gui_menuSelect==1){
          gui_menuSelect=1;
          gui_pageNow+=20;
          gui_changePage(); 
        }
      }
    break;

    case 11:
      if(btn_trig[1]==pressed || btn_trig[2]==pressed){
        if(state_relay==0){
          state_relay=1;
        }
        else{
          state_relay=0;
        }
      }
      else if(btn_trig[3]==pressed){
        gui_menuSelect=0;
        gui_pageNow-=10;
        gui_changePage(); 
        gui_cursorpos(gui_menuSelect);
      }
      gui_runPage(gui_pageNow);
    break;

    case 21:
      if(btn_trig[3]==pressed){
        gui_menuSelect=0;
        gui_pageNow-=20;
        gui_changePage(); 
        gui_cursorpos(gui_menuSelect);
      }
      gui_runPage(gui_pageNow);
    break;

    case 12:
      if(btn_trig[3]==pressed){
        gui_menuSelect=0;
        gui_pageNow-=10;
        gui_changePage(); 
        gui_cursorpos(gui_menuSelect);
      }
      gui_runPage(gui_pageNow);
    break;
    case 22:
      if(btn_trig[4]==pressed){
        state_led++;
        if(state_led>1){
          state_led=0;
        }
        if(state_led==0){
          lcd_putsxy(4,0, "ON-OFF    ");
        }
        else if(state_led==1){
          lcd_putsxy(4,0, "Running   ");
        }
        
      }
      if(btn_trig[1]==pressed){
        led_delay+=100;
        if(led_delay>3000){
          led_delay=0;
        }
        lcd_putsxy(7,1, "       ");
        lcd_putsxy(7,1, String(led_delay));
      }
      else if(btn_trig[2]==pressed){
        led_delay-=100;
        if(led_delay<0){
          led_delay=3000;
        }
        lcd_putsxy(7,1, "       ");
        lcd_putsxy(7,1, String(led_delay));
      }
      if(btn_trig[3]==pressed){
        gui_menuSelect=0;
        gui_pageNow-=20;
        gui_changePage(); 
        gui_cursorpos(gui_menuSelect);
      }
      gui_runPage(gui_pageNow);
    break;

    case 13:
      if(btn_trig[3]==pressed){
        gui_menuSelect=0;
        gui_pageNow-=10;
        gui_changePage(); 
        gui_cursorpos(gui_menuSelect);
      }
    gui_runPage(gui_pageNow);
    break;

    case 23:
      if(btn_trig[4]==pressed){
        state_rgb++;
        if(state_rgb>2){
          state_rgb=0;
        }
        if(state_rgb==0){
          lcd_putsxy(4,0, "Contrast   ");
        }
        else if(state_rgb==1){
          lcd_putsxy(4,0, "Dimming   ");
        }
        else if(state_rgb==2){
          lcd_putsxy(4,0, "Aurora    ");
        }
      }
      if(btn_trig[1]==pressed){
        rgb_delay+=100;
        if(rgb_delay>3000){
          rgb_delay=0;
        }
        lcd_putsxy(7,1, "       ");
        lcd_putsxy(7,1, String(rgb_delay));
      }
      else if(btn_trig[2]==pressed){
        rgb_delay-=100;
        if(rgb_delay<0){
          rgb_delay=3000;
        }
        lcd_putsxy(7,1, "       ");
        lcd_putsxy(7,1, String(rgb_delay));
      }
      if(btn_trig[3]==pressed){
        gui_menuSelect=0;
        gui_pageNow-=20;
        gui_changePage(); 
        gui_cursorpos(gui_menuSelect);
      }
      gui_runPage(gui_pageNow);
    break;

    case 14:
      if(btn_trig[3]==pressed){
        gui_menuSelect=0;
        gui_pageNow-=10;
        gui_changePage(); 
        gui_cursorpos(gui_menuSelect);
      }     
    gui_runPage(gui_pageNow);
    break;

    case 24:
      if(btn_trig[3]==pressed){
        gui_menuSelect=0;
        gui_pageNow-=20;
        gui_changePage(); 
        gui_cursorpos(gui_menuSelect);
      }     
    gui_runPage(gui_pageNow);
    break;

    case 15:
      if(btn_trig[3]==pressed){
        gui_menuSelect=0;
        gui_pageNow-=10;
        gui_changePage(); 
        gui_cursorpos(gui_menuSelect);
      }     
    gui_runPage(gui_pageNow);
    break;
    case 25:
      if(btn_trig[3]==pressed){
        gui_menuSelect=0;
        gui_pageNow-=20;
        gui_changePage(); 
        gui_cursorpos(gui_menuSelect);
      }     
    gui_runPage(gui_pageNow);
    break;

    case 16:
      if(btn_trig[3]==pressed){
        gui_menuSelect=0;
        gui_pageNow-=10;
        gui_changePage(); 
        gui_cursorpos(gui_menuSelect);
      }     
    gui_runPage(gui_pageNow);
    break;
    case 26:
      if(btn_trig[3]==pressed){
        gui_menuSelect=0;
        gui_pageNow-=20;
        gui_changePage(); 
        gui_cursorpos(gui_menuSelect);
      }     
    gui_runPage(gui_pageNow);
    break;
    
    case 17:
      if(btn_trig[3]==pressed){
        gui_menuSelect=0;
        gui_pageNow-=10;
        gui_changePage(); 
        gui_cursorpos(gui_menuSelect);
      }     
    gui_runPage(gui_pageNow);
    break;
    case 27:
      if(btn_trig[3]==pressed){
        gui_menuSelect=0;
        gui_pageNow-=20;
        gui_changePage(); 
        gui_cursorpos(gui_menuSelect);
      }     
    gui_runPage(gui_pageNow);
    break;
    
    //buzzer
    case 18:
      if(btn_trig[3]==pressed){
        gui_menuSelect=0;
        gui_pageNow-=10;
        gui_changePage(); 
        gui_cursorpos(gui_menuSelect);
      }    
      if(btn_trig[1]==pressed){
        buzz_on+=500;
        if(buzz_on>5000){buzz_on=0;}
      }
      if(btn_trig[2]==pressed){
        buzz_off+=500;
        if(buzz_off>5000){buzz_off=0;}
      }
    gui_runPage(gui_pageNow);
    break;
    //servo
    case 28:
      if(btn_trig[1]==pressed){
        servo_sudut+=10;
        if(servo_sudut>180){servo_sudut=180;}
        lcd_putsxy(7,1, "       ");
        lcd_putsxy(7,1, String(servo_sudut));
      }
      if(btn_trig[2]==pressed){
        servo_sudut-=10;
        if(servo_sudut<0){servo_sudut=0;}
        lcd_putsxy(7,1, "       ");
        lcd_putsxy(7,1, String(servo_sudut));
      }
      if(btn_trig[3]==pressed){
        gui_menuSelect=0;
        gui_pageNow-=20;
        gui_changePage(); 
        gui_cursorpos(gui_menuSelect);
      }     
    gui_runPage(gui_pageNow);
    break;
    
    case 19:
      if(btn_trig[3]==pressed){
        gui_menuSelect=0;
        gui_pageNow-=10;
        gui_changePage(); 
        gui_cursorpos(gui_menuSelect);
      }     
    gui_runPage(gui_pageNow);
    break;

    case 29:
      if(btn_trig[3]==pressed){
        gui_menuSelect=0;
        gui_pageNow-=20;
        gui_changePage(); 
        gui_cursorpos(gui_menuSelect);
      }     
    break;

  }
}