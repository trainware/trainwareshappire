/*=================================================== SERVO ===========*/
// Alliasing library Servo menjadi myservo
Servo servo;  

int servo_sudut=0;

// Anda dapat menambahkan servo hingga 12 buah
// Servo myservo2; // Uncomment ini jika ingin menambahkan hingga 2 servo 

void init_servo(){
  servo.attach(pin_Servo);
}

void cont_servo(int pos){
  servo.write(pos);              
}

/*=================================================== BUZZER ===========*/
int buzz_on=0, buzz_off=0;
void init_buzzer(){
  // meng Set pin buzzer pada ESP32 sebagai OUTPUT
  pinMode(pin_Buzzer, OUTPUT);
  buzz_on=0;
  buzz_off=0;
}


byte buz_phase=0;
void cont_buzzer(uint8_t delay_on, uint8_t delay_off){
  unsigned long time_now=millis();
  if(time_now-time_last>=delay_on && buz_phase==1){
    buz_phase=0;
    time_last=time_now;
  }

  if(time_now-time_last>=delay_off && buz_phase==0){
    buz_phase=1;
    time_last=time_now;
  }
    
  if(buz_phase==1){
      // fungsi membunyikan buzzer
      digitalWrite(pin_Buzzer, HIGH);
  }
  else if(buz_phase==0){
      // fungsi mesilentkan buzzer
      digitalWrite(pin_Buzzer, LOW);
  }
}