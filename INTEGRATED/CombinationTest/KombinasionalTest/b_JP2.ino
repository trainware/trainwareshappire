/*=================================================== LED ===========*/
void init_led(){
  // Inisasi pin pada ESP32 sebagai OUTPUT
  pinMode(pin_Led_1, OUTPUT);
  pinMode(pin_Led_2, OUTPUT);
  pinMode(pin_Led_3, OUTPUT);
  pinMode(pin_Led_4, OUTPUT);
}

void cont_led(byte led, byte state){
  digitalWrite(led, state);
}

void cont_led_on_off(byte led, uint16_t delays){
  digitalWrite(led, HIGH);
  delay(delays);
  digitalWrite(led, LOW);
  delay(delays);
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