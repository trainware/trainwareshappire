void gui_changePage(){
  switch(gui_pageNow){
    case 0:
      Serial.println(gui_pageNow);
      menuSelect=1;
      gui_pageNow=99;
      break;
    case 99:
      menuSelect=1; 
      lcd.clear();
      lcd_putsxy(0, 0, "Trainware");
      lcd_putsxy(1, 1 , "Kombinasional | mulai ? ");
      break;
    
    case 1:
      menuSelect=0;
      lcd_clear();
      lcd_putsxy(1,0, "Gas Leakage Alarm");
      lcd_putsxy(1,1, "Fire Alarm");
      break;
    case 11:
      menuSelect=1;
      lcd_clear();
      lcd_putsxy(0,0, "Gas : ");
      break;
    case 21:
      menuSelect=1;
      lcd_clear();
      lcd_putsxy(0,0, "PIR Read");
      break;

    case 2:
      menuSelect=0;
      lcd_clear();
      lcd_putsxy(1,0, "Rain Alarm");
      lcd_putsxy(1,1, "RFID Door");
      break;
    case 12:
      menuSelect=1;
      lcd_clear();
      lcd_putsxy(0, 0, "US Read");
      lcd_putsxy(0, 1, "Jarak :");
      break;
    case 22:
      menuSelect=1;
      lcd_clear();
      lcd_putsxy(0,0, "LED Test");
      break;
    
    case 3:
      menuSelect=0;
      lcd_clear();
      lcd_putsxy(1,0, "Keypad Pass Lock");
      lcd_putsxy(1,1, "Volume Control");
      break;
    case 13:
      menuSelect=1;
      lcd_clear();
      lcd_putsxy(0, 0, "RFID Read");
      lcd_putsxy(0, 1, "ID :");
      break;
    case 23:
      menuSelect=1;
      lcd_clear();
      lcd_putsxy(0,0, "RGB Test");
      break;
    
    case 4:
      menuSelect=0;
      lcd_clear();
      lcd_putsxy(1,0, "Plant Monitoring");
      lcd_putsxy(1,1, "Ready soon!");
      break;
    case 14:
      menuSelect=1;
      lcd_clear();
      lcd_putsxy(0, 0, "RFID Read");
      lcd_putsxy(0, 1, "ID :");
      break;
    case 24:
      menuSelect=1;
      lcd_clear();
      lcd_putsxy(0,0, "RGB Test");
      break;

    case 5:
      menuSelect=0;
      lcd_clear();
      lcd_putsxy(1,0, "JP4-FLAME");
      lcd_putsxy(1,1, "JP4-Potensiometer");
      break;
    case 15:
      menuSelect=1;
      lcd_clear();
      lcd_putsxy(0, 0, "Flame Read");
      break;
    case 25:
      menuSelect=1;
      lcd_clear();
      lcd_putsxy(0,0, "Potensio Read");
      lcd_putsxy(1,1, "ADC:");
      lcd_putsxy(10,1, "| ");
      break;
    
    case 6:
      menuSelect=0;
      lcd_clear();
      lcd_putsxy(1,0, "JP5-RTC");
      lcd_putsxy(1,1, "JP5-Oled");
      break;
    case 16:
      menuSelect=1;
      lcd_clear();
      lcd_putsxy(0, 0, "Time Now");
      break;
    case 26:
      menuSelect=1;
      lcd_clear();
      lcd_putsxy(0,0, "Play Gambar :");
      break;
    
    case 7:
      menuSelect=0;
      lcd_clear();
      lcd_putsxy(1,0, "JP6-Gas");
      lcd_putsxy(1,1, "JP6-Rain");
      break;
    case 17:
      menuSelect=1;
      lcd_clear();
      lcd_putsxy(0, 0, "Methane Gas");
      lcd_putsxy(1, 1, "D0:");
      lcd_putsxy(6, 1, "A0:");
      break;
    case 27:
      menuSelect=1;
      lcd_clear();
      lcd_putsxy(0,0, "Rain Sense");
      lcd_putsxy(1, 1, "D0:");
      lcd_putsxy(6, 1, "A0:");
      break;
    
    case 8:
      menuSelect=0;
      lcd_clear();
      lcd_putsxy(1,0, "JP7-Buzzer");
      lcd_putsxy(1,1, "JP7-Servo");
      break;
    case 18:
      menuSelect=1;
      lcd_clear();
      lcd_putsxy(0, 0, "Buzzer Test");
      break;
    case 28:
      menuSelect=1;
      lcd_clear();
      lcd_putsxy(0,0, "Servo Degree");
      lcd_putsxy(10,0, "-> Enter");
      break;
    
  }
}