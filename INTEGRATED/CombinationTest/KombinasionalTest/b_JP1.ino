/*=================================================== RELAY ===========*/

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

void read_PIR(){
  bool state_pir = digitalRead(pin_Pir);
  
  if (state_pir == 0){
    Serial.println("Motion Tidak Terdeteksi");  
  } 
  else {
    Serial.println("Motion Terdeteksi");    
  }
  delay(100);
}
