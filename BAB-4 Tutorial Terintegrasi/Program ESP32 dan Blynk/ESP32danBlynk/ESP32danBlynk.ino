// Untuk kebutuhan Library Blynk
#define BLYNK_PRINT Serial

// Isi Data berikut berdasarkan yang dikirimkan ke email anda
// anda juga dapat melihatnya di Web dashboard blynk anda
#define BLYNK_TEMPLATE_ID   "TMPL6mTASbPAb"
#define BLYNK_TEMPLATE_NAME "TrainWare"
#define BLYNK_AUTH_TOKEN    "0jqKdmxNZhm241wUcn37Rt9yC_fmUZDl"

// Memasukkkan library yang diperlukan
#include <WiFi.h>
#include <WiFiClient.h>
// Library Blynk
#include <BlynkSimpleEsp32.h>

// Inisialisasi variable Char untuk fungsi Blynk.begin
char auth[] = BLYNK_AUTH_TOKEN; 
char ssid[] = "NKRI1";
char pass[] = "indonesia1968"; // Jika tidak menggunakan password kosongkan "";

// Mendefinisikan pin LED-3 dan LED-4 pada ESP32
#define pin_Led_3   27
#define pin_Led_4   2

// Mendefinisikan pin Potensiometer pada ESP32
#define pin_Pot     36

// Membuat Fungsi MAP untuk mengatur nilai Minimal & Maksimal (Re-scale)
float floatMap(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

// Iniasalisasi variable untuk Value LED 3 dan LED 4
int led_3_value=0;
int led_4_value=0;

// Fungsi untuk membaca Variable V1 dari Blynk ke ESP32
BLYNK_WRITE(V1)
{
  led_3_value = param.asInt(); //
}

// Fungsi untuk membaca Variable V5 dari Blynk ke ESP32
BLYNK_WRITE(V5)
{
  led_4_value = param.asInt(); //
}

// Inisialisasi variable Timer dari Blynk
BlynkTimer timer;

// Fungsi yang akan dieksekusi tiap Timer Aktif (1 Detik)
void myTimerEvent()
{
  
  // Membaca Nilai Input Analog pada Pin GPIO-36
  // Lalu menyimpannya dalam variable "analogValue"
  int analogValue = analogRead(pin_Pot);
  // Rescale Nilai yang dibaca dari ADC (0-4095 menjadi 0-100 %)
  float percentage = floatMap(analogValue, 0, 4095, 0, 100);

  // Mencetak Nilai Mentah ADC yang didapat (0-4095)
  Serial.print("Analog: ");
  Serial.print(analogValue);

  // Mencetak Nilai Hasil fungsi MAP / Re-Scale (0-100%)
  Serial.print(", Percentage: ");
  Serial.print(percentage);
  
  // Mencetak nilai Dimmer LED 4
  Serial.print(", Led 4 val : ");
  Serial.println(led_4_value);

  // Fungsi untuk mengirim nilai dari ESP32 ke Blynk 
  // Batas anda mengirim data ke Blynk adalah 10 data per Detik.
  Blynk.virtualWrite(V4, percentage);
}

void setup()
{
  // Inisialisasi Serial dengan Baudrate 115200
  Serial.begin(115200);
  // Inisialisasi Blynk
  Blynk.begin(auth, ssid, pass);

  // Inisialisasi Timer yang akan jalan tiap 1 Detik
  timer.setInterval(1000L, myTimerEvent);

  // Meng set Pin LED menjadi Mode OUTPUT
  pinMode(pin_Led_3, OUTPUT);
  pinMode(pin_Led_4, OUTPUT);
}

void loop()
{

  // Fungsi Control LED 3 untuk Toggling
  // nilai led_3_value adalah 0 & 1
  digitalWrite(pin_Led_3, led_3_value);
  
  // Fungsi Control LED 4 untuk Dimming 
  // nilai led_4_value adalah 0 - 255
  analogWrite(pin_Led_4, led_4_value);
  delay(50);

  Blynk.run(); // Menjalankan Blynk
  timer.run(); // Menjalankan Timer
}