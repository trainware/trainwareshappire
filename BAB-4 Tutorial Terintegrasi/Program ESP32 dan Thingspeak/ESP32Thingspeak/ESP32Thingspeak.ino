/* ==================

  TrainWare
  ESP32 ThingSpeak untuk Menampilkan Chart

  ESP32 terhubung ke Wifi yang memiliki Akses Internet, yang kemudian
  akan terhubung dengan Thingspeak.

  Thingspeak tidak dapat digunakan untuk memberikan kontrol ke ESP32. 
  Hanya Monitoring saja.

  INPUT : 
  - JP4     Pembacaan ADC Potensiometer 
  - NON JP  DHT

  Library yang harus diinstall oleh anda:
  Thingspeak.h by MathWorks 2.0.1

================== */

// Memasukkan Library Wifi.h, Thingspeak.h kedalam program ini
#include <WiFi.h>
#include "ThingSpeak.h"

// Isikan SSID dan Password Wifi Anda
// disarankan untuk menghindari spasi 
const char* ssid = "NKRI1";   // your network SSID (name) 
const char* password = "indonesia1968";   // your network password

WiFiClient  client;

// Isikan variabel berikut sesuai yang ada di Thingspeak anda
unsigned long myChannelNumber = 1;
const char * myWriteAPIKey = "48S9IJK9XMRQ90Z4";

// inisialisasi library DHT Sensor
#include "DHT.h"

// definisi pin yang digunakan ESP32 untuk Sensor DHT
#define pin_DHT     16

// Anda dapat menggunakan Library ini untuk DHT11, DHT22, dan DHT21
// Uncomment salah 1 dari 3, tergantung dari sensor yang digunakan
#define DHTTYPE DHT11   // DHT 11
// #define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

// Aliasing Library DHT -> dht
DHT dht(pin_DHT, DHTTYPE);

// Mendefinisikan pin Potensiometer pada ESP32
#define pin_Pot     36

// Mendefinisikan pin LED 4 pada ESP32
#define pin_Led_4   2

// Membuat Fungsi MAP untuk mengatur nilai Minimal & Maksimal (Re-scale)
float floatMap(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

// Timer variables
unsigned long lastTime = 0;
unsigned long timerDelay = 30000;

void setup() {
  // Inisialisasi Serial
  Serial.begin(115200);

  // Inisialisasi Pin 4 menjadi OUTPUT
  pinMode(pin_Led_4, OUTPUT);

  WiFi.begin(ssid, password);
  
  // Mengubah mode ESP32 ke Wifi STA
  // artinya ESP32 terhubung ke sebuah Access Point
  WiFi.mode(WIFI_STA);   
  
  // Fungsi memulai Thingspeak 
  ThingSpeak.begin(client);  // Initialize ThingSpeak
}

void loop() {
  // Membaca Nilai Input Analog pada Pin GPIO-36
  // Lalu menyimpannya dalam variable "analogValue"
  int analogValue = analogRead(pin_Pot);
  // Rescale Nilai yang dibaca dari ADC (0-4095 menjadi 0-100 %)
  float percentPot = floatMap(analogValue, 0, 4095, 0, 100);
  // Fungsi berikut akan dieksekusi tiap "timerDelay" ms
  if ((millis() - lastTime) > timerDelay) {

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
    
    // Cek lagi apakah ESP32 masih terhubung wifi atau tidak
    if(WiFi.status() != WL_CONNECTED){
      Serial.print("Attempting to connect");
      while(WiFi.status() != WL_CONNECTED){
        WiFi.begin(ssid, password);
        Serial.print(ssid) ;
        Serial.print(" | ");
        Serial.println(password);
        delay(500);     
        Serial.println(".");
      } 
      Serial.println("\nConnected.");
    }
    
    // Menyimpan variable yang akan dikirimkan
    // Anda dapat mengirimkan maksimal 8 field ke Thingspeak
    ThingSpeak.setField(1, percentPot);
    ThingSpeak.setField(2, t);
    
    int x = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);

    // Jika return dari variable "x" = 200, maka sukses. Jika selain itu maka tidak sukses.
    if(x == 200){
      Serial.println("Sukses Update Channel Thingspeak");
      Serial.println("data terkirim");
      Serial.println("Percent Potensio:" + String(percentPot) + " %");
      Serial.println("Suhu DHT:" + String(t) + " °C");
    }
    else{
      Serial.println("Tidak Sukses update data Thingspeak. Error : " + String(x));
    }
    lastTime = millis();
  }
}