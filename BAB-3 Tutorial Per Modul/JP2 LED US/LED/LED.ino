/* ==================
  TrainWare
  LED Code  
=================== */

// Mendefinisikan pin LED-1 sampai LED-4 pada ESP32
#define pin_Led_1   32
#define pin_Led_2   33
#define pin_Led_3   27
#define pin_Led_4   2

// Mendefinisikan variable untuk mengatur Delay LED
unsigned long time_last=0;
byte led_state=0;

// Kontrol LED Advanced Tanpa Menggunakan Fungsi "Delay(time)"
void cont_led_on_off(int delays){
  unsigned long time_now=millis();

  Serial.print(time_now);
  Serial.print(" | ");
  Serial.println(time_last);
  if(time_now-time_last>=delays){
    if(led_state==1){led_state=0;}
    else if(led_state==0){led_state=1;}
    time_last=time_now;
    Serial.println("Ganti");
  }
  
  if(led_state==1){
    digitalWrite(pin_Led_1, HIGH);
    digitalWrite(pin_Led_2, HIGH);
    digitalWrite(pin_Led_3, HIGH);
    digitalWrite(pin_Led_4, HIGH);
  }
  else if(led_state==0){
    digitalWrite(pin_Led_1, LOW);
    digitalWrite(pin_Led_2, LOW);
    digitalWrite(pin_Led_3, LOW);
    digitalWrite(pin_Led_4, LOW);
  }
}

void setup() {
  // Inisialiasasi Serial, dengan baudrate 115200
  Serial.begin(115200);

  // Meng set Pin Semua LED menjadi Mode OUTPUT
  pinMode(pin_Led_1, OUTPUT);
  pinMode(pin_Led_2, OUTPUT);
  pinMode(pin_Led_3, OUTPUT);
  pinMode(pin_Led_4, OUTPUT);
}

void loop() {

  // Fungsi untuk mengkontrol LED dengan mengisikan 6000ms sebagai Delaynya
  cont_led_on_off(6000);

  // Fungsi untuk menampilkan status LED pada Serial Monitor
  Serial.println(led_state);
}
