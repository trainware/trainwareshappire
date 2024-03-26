/*=================================================== SERVO ===========*/
// Alliasing library Servo menjadi myservo
Servo servo;  
// Anda dapat menambahkan servo hingga 12 buah
// Servo myservo2; // Uncomment ini jika ingin menambahkan hingga 2 servo 

void init_servo(){
  servo.attach(pin_Servo);
}

void cont_servo(int pos){
  servo.write(pos);              
}

/*=================================================== BUZZER ===========*/
void init_buzzer(){
  // meng Set pin buzzer pada ESP32 sebagai OUTPUT
  pinMode(pin_Buzzer, OUTPUT);
}

void cont_buzzer(uint8_t delay_on, uint8_t delay_off){
    // fungsi membunyikan buzzer
    digitalWrite(pin_Buzzer, HIGH);

    //delay lama buzzer bunyi
    delay(delay_on);

    // fungsi mesilentkan buzzer
    digitalWrite(pin_Buzzer, LOW);

    //delay lama buzzer mati
    delay(delay_off);
}