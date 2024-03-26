/*=================================================== LED ===========*/
int led_delay=0;
int state_led=0;

void init_led(){
  // Inisasi pin pada ESP32 sebagai OUTPUT
  pinMode(pin_Led_1, OUTPUT);
  pinMode(pin_Led_2, OUTPUT);
  pinMode(pin_Led_3, OUTPUT);
  pinMode(pin_Led_4, OUTPUT);

  state_led=0;
}

void cont_led(byte led, byte state){
  digitalWrite(led, state);
}


byte led_phase;

void cont_led_on_off(int delays){
  unsigned long time_now=millis();


  if(time_now-time_last>=delays){
    if(led_phase==1){led_phase=0;}
    else{led_phase=1;}
    time_last=time_now;
  }
  
  if(led_phase==1){
    cont_led(pin_Led_1, HIGH);
    cont_led(pin_Led_2, HIGH);
    cont_led(pin_Led_3, HIGH);
    cont_led(pin_Led_4, HIGH);
  }
  else if(led_phase==0){
    cont_led(pin_Led_1, LOW);
    cont_led(pin_Led_2, LOW);
    cont_led(pin_Led_3, LOW);
    cont_led(pin_Led_4, LOW);
  }
}

void cont_led_running(int delays){
  unsigned long time_now = millis();

  if(time_now-time_last>=delays){
    cont_led(pin_Led_1, HIGH);  
    cont_led(pin_Led_2, LOW);
    cont_led(pin_Led_3, LOW);
    cont_led(pin_Led_4, LOW);
  }
  if(time_now-time_last>=delays*2){
    cont_led(pin_Led_1, LOW);
    cont_led(pin_Led_2, HIGH);  
    cont_led(pin_Led_3, LOW);
    cont_led(pin_Led_4, LOW);
  }
  if(time_now-time_last>=delays*3){
    cont_led(pin_Led_1, LOW);
    cont_led(pin_Led_2, LOW);
    cont_led(pin_Led_3, HIGH);  
    cont_led(pin_Led_4, LOW);
  }
  if(time_now-time_last>=delays*4){
    cont_led(pin_Led_1, LOW);
    cont_led(pin_Led_2, LOW);
    cont_led(pin_Led_3, LOW);
    cont_led(pin_Led_4, HIGH);  
  }
  if(time_now-time_last>=delays*5){
    time_last=time_now;
  }
}

/*=================================================== ULTRASONIC ===========*/
// deklarasi variable
long durasi;
float jarakCM;

// mendefinisikan nilai kecepatan suara (cm/us)
#define SOUND_SPEED 0.034

// Mendefinisikan nilai Variable Pengali CM ke Inchi
#define CM_TO_INCH 0.393701

void init_us(){
  // Mengatur Mode Pin Trigger dan Echo
  pinMode(pin_Trig, OUTPUT); 
  pinMode(pin_Echo, INPUT);
}

float read_us(){
  digitalWrite(pin_Trig, LOW);

  // Jeda 2 Mikrodetik
  delayMicroseconds(2);
  
  // Meng set HIGH pada Pin Trigger selama 10 mikrodetik
  digitalWrite(pin_Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pin_Trig, LOW);
  
  // Membaca nilai pin ECHO yang mendapat sinyal dari gelombang pantul
  int durasi = pulseIn(pin_Echo, HIGH);
  
  // Menghitung jarak dari nilai pin ECHO
  float jarakCM = (float)durasi * SOUND_SPEED/2;
  
  return jarakCM;
}