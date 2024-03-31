/*=================================================== RAIN ===========*/
void init_rain(){
  pinMode(pin_D0Rain, INPUT);
}

int read_A0rain(){
  // Return variable untuk menyimpan Nilai Pembacaan sensor rain secara Analog
  return analogRead(pin_A0Rain);
}

int read_D0rain(){
  // Return variable untuk menyimpan Nilai Pembacaan sensor rain secara digital
  return digitalRead(pin_D0Rain);
}

/*=================================================== BUTTON ===========*/
// array buffer state dari suatu button
unsigned char btn_trig[6]={0xFF,0xFF,0xFF,0xFF,0xFF};

void init_button(){
  pinMode(pin_BtDown,INPUT);
  pinMode(pin_BtUp,INPUT);
  pinMode(pin_BtEnter,INPUT);
  pinMode(pin_BtBack,INPUT);
}

void bt_test(){
  // Serial.println(btn_trig[4]);
  if(btn_trig[1]==pressed){Serial.println("Up");}    
  if(btn_trig[2]==pressed){Serial.println("Down");}    
  if(btn_trig[3]==pressed){Serial.println("Back");}    
  if(btn_trig[4]==pressed){Serial.println("Enter");}    
}

void bt_scan(byte Button_pin,int btn){
  if(digitalRead(Button_pin)==HIGH){
    btn_trig[btn]=(btn_trig[btn]<<2|0);
  }
  else if(digitalRead(Button_pin)==LOW){
    btn_trig[btn]=(btn_trig[btn]<<1)|1;
  }
}

void bt_allscan(){
  bt_scan(pin_BtDown,1);
  bt_scan(pin_BtUp,2);
  bt_scan(pin_BtBack,3);
  bt_scan(pin_BtEnter,4);
}

/*=================================================== GAS ===========*/
void init_gas(){
  pinMode(pin_D0Gas, INPUT);
}

int read_A0gas(){
  // Return variable untuk menyimpan Nilai Pembacaan sensor Gas secara Analog
  return analogRead(pin_A0Gas);
}

int read_D0gas(){
  // Return variable untuk menyimpan Nilai Pembacaan sensor Gas secara digital
  return digitalRead(pin_D0Gas);
}