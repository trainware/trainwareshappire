void gui_changePage(){
  switch(gui_pageNow){
    case 0:
      Serial.println(gui_pageNow);
      gui_menuSelect=1;
      gui_pageNow=99;
      break;
    case 99:
      gui_menuSelect=1;
      lcd.clear();
      lcd_putsxy(0, 0, "Trainware");
      lcd_putsxy(1, 1 , "mulai ? ");
      gui_cursorpos(gui_menuSelect);
      break;
    
    case 1:
      lcd.clear();
      lcd_putsxy(1,0, "JP1-Relay");
      lcd_putsxy(1,1, "JP1-PIR");
      break;
    case 11:
      lcd.clear();
      lcd_putsxy(0,0, "Relay Test");
      init_relay();
      break;
    case 21:
      lcd.clear();
      lcd_putsxy(0,0, "PIR Motion :");
      init_PIR();
      break;

    case 2:
      lcd.clear();
      lcd_putsxy(1,0, "JP2-Ultrasonic");
      lcd_putsxy(1,1, "JP2-LED");
      digitalWrite(pin_Led_1, LOW);
      digitalWrite(pin_Led_2, LOW);
      digitalWrite(pin_Led_3, LOW);
      digitalWrite(pin_Led_4, LOW);
      break;
    case 12:
      lcd.clear();
      lcd_putsxy(0, 0, "US Read");
      lcd_putsxy(0, 1, "Jarak:");
      init_us();
      break;
    case 22:
      lcd.clear();
      lcd_putsxy(0,0, "LED ON-OFF");
      lcd_putsxy(0,1, "Delay: 0");
      init_led();
      break;
    
    case 3:
      lcd.clear();
      lcd_putsxy(1,0, "JP3-RFID");
      lcd_putsxy(1,1, "JP3-RGB");
      break;
    case 13:
      lcd.clear();
      lcd_putsxy(0, 0, "RFID Read");
      lcd_putsxy(0, 1, "ID:");
      init_rfid();
      break;
    case 23:
      lcd.clear();
      lcd_putsxy(0,0, "RGB Contrast");
      lcd_putsxy(0,1, "Delay: 100");
      init_rgb();
      break;
    
    case 4:
      lcd.clear();
      lcd_putsxy(1,0, "JP3-KEYPAD");
      lcd_putsxy(1,1, "JP4-SOIL SENSE");
      break;
    case 14:
      lcd.clear();
      lcd_putsxy(0, 0, "KEYPAD Test");
      lcd_putsxy(0, 1, "Insert:");
      break;
    case 24:
      lcd.clear();
      lcd_putsxy(0,0, "Soil Sense Value");
      lcd_putsxy(0,1, "D0:");
      lcd_putsxy(8,1, "A0:");
      init_soil();
      break;

    case 5:
      lcd.clear();
      lcd_putsxy(1,0, "JP4-FLAME");
      lcd_putsxy(1,1, "JP4-Potensiometer");
      break;
    case 15:
      lcd.clear();
      lcd_putsxy(0, 0, "Flame Read");
      init_flame();
      break;
    case 25:
      lcd.clear();
      lcd_putsxy(0,0, "Potensio Read");
      lcd_putsxy(1,1, "ADC:");
      lcd_putsxy(10,1, "| ");
      break;
    
    case 6:
      lcd.clear();
      lcd_putsxy(1,0, "JP5-RTC");
      lcd_putsxy(1,1, "JP5-Oled");
      break;
    case 16:
      lcd.clear();
      lcd_putsxy(0, 0, "Time:");
      init_rtc();
      break;
    case 26:
      lcd.clear();
      lcd_putsxy(0,0, "Oled Test");
      lcd_putsxy(0,1, "Play Gambar");
      init_oled();
      break;
    
    case 7:
      lcd.clear();
      lcd_putsxy(1,0, "JP6-Gas");
      lcd_putsxy(1,1, "JP6-Rain");
      init_button();
      break;
    case 17:
      lcd.clear();
      lcd_putsxy(0, 0, "Mohon maaf");
      lcd_putsxy(0, 1, "Pin == Button");
      init_gas();
      break;
    case 27:
      lcd.clear();
      lcd_putsxy(0, 0, "Mohon maaf");
      lcd_putsxy(0, 1, "Pin == Button");
      init_rain();
      break;
    
    case 8:
      lcd.clear();
      lcd_putsxy(1,0, "JP7-Buzzer");
      lcd_putsxy(1,1, "JP7-Servo");
      digitalWrite(pin_Buzzer, LOW);
      break;
    case 18:
      lcd.clear();
      lcd_putsxy(0, 0, "Buzzer Test");
      lcd_putsxy(0, 1, "ON:");
      lcd_putsxy(8, 1, "OFF:");
      init_buzzer();
      break;
    case 28:
      lcd.clear();
      lcd_putsxy(0,0, "Servo Test");
      lcd_putsxy(0,1, "Sudut: 0");
      init_servo();
      break;
    
    case 9:
      lcd.clear();
      lcd_putsxy(1,0, "DHT Sense");
      lcd_putsxy(1,1, "Terima kasih");
      break;
    case 19:
      lcd.clear();
      lcd_putsxy(0, 0, "DHT Test");
      lcd_putsxy(4, 0, "Hum:");
      lcd_putsxy(4, 1, "T:");
      init_dht();
      break;
  }
}