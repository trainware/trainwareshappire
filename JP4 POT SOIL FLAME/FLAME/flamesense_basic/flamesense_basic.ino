/* ==================
  TrainWare
  Flame Sensor Code
=================== */

// Mendefinisikan pin Flame Sensor pada ESP32
#define pin_Flame  39

void setup() {
  // Inisialiasasi Serial, dengan baudrate 115200
  Serial.begin(115200);

  // meng Set pin flame sensor pada ESP32 sebagai INPUT
  pinMode(pin_Flame, INPUT);
}

void loop() {
  // Deklarasi variable untuk menyimpan Nilai Digital
  int firesensorDigital = digitalRead(pin_Flame);

  // Menampilkan hasil pembacaan Digital untuk sensor
  Serial.print("Status Api Terdeteksi : ");
  Serial.println(firesensorDigital);

  // Jeda 100 mili detik 
  delay(100);
}