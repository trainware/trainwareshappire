/* ==================
  TrainWare
  Buzzer Control Code
=================== */

// mendefinisikan pin Buzzer pada ESP32
#define buzzerPin  26

void setup() {
  
  // Inisialiasasi Serial, dengan baudrate 115200
  Serial.begin(115200);

  // meng Set pin buzzer pada ESP32 sebagai OUTPUT
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Mengatur LOGIC LOW pada pin buzzer selama 3 detik
  digitalWrite(buzzerPin, LOW);
  // Atur nilai berikut untuk durasi off buzzer
  delay(3000); 
  
  // Mengatur LOGIC HIGH pada pin buzzer selama 1 detik
  digitalWrite(buzzerPin, HIGH);
  // Atur nilai berikut untuk durasi on buzzer
  delay(1000);
}