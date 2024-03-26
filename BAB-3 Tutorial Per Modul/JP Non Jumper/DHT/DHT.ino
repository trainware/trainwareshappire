/* ==================
 Code By TrainWare 
 DHT Sensor Code 
=================== */


// inisialisasi library DHT Sensor
#include "DHT.h"

// definisi pin yang digunakan ESP32 untuk Sensor DHT
#define pin_DHT 16

// Anda dapat menggunakan Library ini untuk DHT11, DHT22, dan DHT21
// Uncomment salah 1 dari 3, tergantung dari sensor yang digunakan
#define DHTTYPE DHT11   // DHT 11
// #define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

// Aliasing Library DHT -> dht
DHT dht(pin_DHT, DHTTYPE);

void setup() {
  // Inisialisasi Serial
  Serial.begin(115200);
  // Fungsi Start DHT
  dht.begin();
}

void loop() {
  // Jeda 2 detik pengukuran
  delay(500);

  // Pembacaaan temperature dan kelembapan
  // membutuhkan waktu 250ms hingga 2 detik
  // Fungsi membaca nilai kelembapan
  float h = dht.readHumidity();
  // Fungsi membaca nilai Suhu (Celcius)
  float t = dht.readTemperature();
  // Fungsi membaca nilai Suhu (Fahrenhait)
  float f = dht.readTemperature(true);

  // Fungsi mengecek data yang didapat Valid atau Tidak
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print(F("Kelembapan: "));
  Serial.print(h);
  Serial.print(F("%  Suhu: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));
}