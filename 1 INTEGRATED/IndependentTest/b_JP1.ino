/*=================================================== RELAY ===========*/

byte state_relay=0;


void init_relay(){
  // meng Set pin Relay pada ESP32 sebagai OUTPUT
  pinMode(pin_Relay, OUTPUT);
} 

void cont_relay(byte state){
  digitalWrite(pin_Relay, state);
}

/*=================================================== PIR ===========*/
void init_PIR(){
  // Meng set Pin motionSensor menjadi Mode Input PullUP
  pinMode(pin_Pir, INPUT_PULLUP);
}

byte read_PIR(){
  return digitalRead(pin_Pir); 
}
