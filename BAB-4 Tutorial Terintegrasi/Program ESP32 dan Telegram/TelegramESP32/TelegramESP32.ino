/* ==================
  
  TrainWare
  ESP32 Telegram with TelegramBot

  Bekerja dengan memanfaatkan Bot yang ada di telegram
  Code ini akan bekerja untuk kontrol Output maupun pembacaan Input ESP32

  OUTPUT : 
  - Kontrol LED 3 dan LED 4
  - Kontrol Relay

  INPUT : 
  - Pembacaan ADC Potensiometer 
  - DHT

  Sebelum menggunakan code ini baca baik-baik panduan
  untuk menyiapkan Bot Telegram Anda

  Library yang harus diinstall oleh anda:
  ArduinoJson.h
  UniversalTelegramBot.h

=================== */

// Memasukkan Library Wifi.h, WifiClientSecure.h, UniversalTelegramBot.h, ArduinoJson.h kedalam program ini
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <ArduinoJson.h>

// inisialisasi library DHT Sensor
#include "DHT.h"

// Isikan SSID dan Password Wifi Anda
// disarankan untuk menghindari spasi 
const char* ssid = "NKRI1";
const char* password = "indonesia1968";

// Isi dengan BOT Token yang sudah anda dapatkan dari BotFather
#define BOTtoken "6476375965:AAGYWKeaD84ao15fDhLtuaQPXpCi_ZABV_A" 

// Gunakan @myidbot untuk mengetahui ID Telegram yang harus mendapatkan datanya
// Bisa berupa Individu atau Group
// Anda harus menekan /start pada bot Anda supaya anda bisa menerima pesan tersebut
#define CHAT_ID "382168651"

// Membuat Wifi Client dengan WifiClientSecure
WiFiClientSecure client;

// Membuat bot dengan Token dan Cliend yang sudah didefinisikan diatas
UniversalTelegramBot bot(BOTtoken, client);

// Cek apakah ada pesan masuk tiap 1 Detik
int botRequestDelay = 1000;
unsigned long lastTimeBotRan;

// Mendefinisikan pin LED-3 dan LED-4 pada ESP32
#define pin_Led_3   27
#define pin_Led_4   2

// mendefinisikan pin Relay pada ESP32
#define pin_Relay  25

// Mendefinisikan pin Potensiometer pada ESP32
#define pin_Pot 36

unsigned char countpot=0;

// Membuat Fungsi MAP untuk mengatur nilai Minimal & Maksimal (Re-scale)
float floatMap(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

// Menyimpan state LED-3, LED-4, dan RELAY pada variable
bool ledState3= LOW;
bool ledState4= LOW;
bool relaystate= LOW;

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

  Serial.begin(115200);

  // Meng Set pin LED pada ESP32 sebagai OUTPUT
  pinMode(pin_Led_4, OUTPUT);
  pinMode(pin_Led_3, OUTPUT);

  // Meng Set pin Relay pada ESP32 sebagai OUTPUT
  pinMode(pin_Relay, OUTPUT);

  // Menghubungkan ESP32 dengan Network Anda
  Serial.print("Connecting Wifi: ");
  Serial.println(ssid);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  // Fungsi Start DHT
  dht.begin();
  
  // Menambahkan root certificate untuk api.telegram.org
  client.setCACert(TELEGRAM_CERTIFICATE_ROOT); 
  
  // Jika belum konek maka serial akan print . . .
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  // Jika berhasil konek maka akan ada tulisan "Wifi connected"
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  // Bot akan mengirim pesan ke Telegram bahwa Bot dan ESP32 siap digunakan
  bot.sendMessage(CHAT_ID, "Bot Siap. klik /start untuk memulai", "");
}

// 
void loop() {
  // Tiap 1 detik maka akan dijalankan perintah berikut
  if (millis() > lastTimeBotRan + botRequestDelay)  {
    int numPesanBaru = bot.getUpdates(bot.last_message_received + 1);

    // Membaca Nilai Input Analog pada Pin GPIO-36
    // Lalu menyimpannya dalam variable "analogValue"
    int analogValue = analogRead(pin_Pot);
    // Rescale Nilai yang dibaca dari ADC (0-4095 menjadi 0-100 %)
    float percentPot = floatMap(analogValue, 0, 4095, 0, 100);

    // Tiap 10 detik fungsi berikut akan di eksekusi
    if(countpot++>=10){
      String sendPot = "Pot : " + String(percentPot) + " %";
      bot.sendMessage(CHAT_ID, sendPot, "");
      countpot=0;
    }

    while(numPesanBaru) {
      Serial.println("got response");
      handlePesanBaru(numPesanBaru);
      numPesanBaru = bot.getUpdates(bot.last_message_received + 1);
    }
    lastTimeBotRan = millis();
  }
}

// Fungsi untuk Handle Jika ada Pesan Baru
// Jumlah pesan Baru akan disimpan dalam variable numPesanBaru
void handlePesanBaru(int numPesanBaru) {
  Serial.println("handlePesanBaru");
  Serial.println(String(numPesanBaru));

  for (int i=0; i<numPesanBaru; i++) {
    // Cek apakah Pesan Baru dari ID yang sudah di Authorized oleh anda
    // Berdasarkan CHAT_ID
    String chat_id = String(bot.messages[i].chat_id);
    if (chat_id != CHAT_ID){
      bot.sendMessage(chat_id, "Pengguna Tidak dikenal", "");
      continue;
    }
    
    // Cetak Pesan baru yang diterima
    String text = bot.messages[i].text;
    Serial.println(text);

    // Cetak Nama pengirim pesan
    String from_name = bot.messages[i].from_name;

    // Cek jika menerima chat pesan baru "/start" maka eksekusi perintah berikut 
    if (text == "/start") {
      String welcome = "Selamat Datang, " + from_name + ".\n";
      welcome += "Gunakan Perintah Berikut untuk mengkontrol ESP32 anda\n\n";
      welcome += "/led3_on untuk menyalakan LED 3\n";
      welcome += "/led3_off untuk mematikan LED 3\n";
      welcome += "/led4_on untuk menyalakan LED 4\n";
      welcome += "/led4_off untuk mematikan LED 4\n";
      welcome += "/relay_on untuk menyalakan LED 4\n";
      welcome += "/relay_off untuk mematikan LED 4\n";
      welcome += "/cekledrelay untuk request kondisi LED 3 dan LED 4 sekarang\n";
      welcome += "/cekruangan untuk request kondisi LED 3 dan LED 4 sekarang\n";
      bot.sendMessage(chat_id, welcome, "");
    }

    // Cek jika menerima chat pesan baru "/led3_on" maka led 3 harus dinyalakan
    if (text == "/led3_on") {
      bot.sendMessage(chat_id, "LED 3 state set to ON", "");
      ledState3 = HIGH;
      digitalWrite(pin_Led_3, ledState3);
    }
    
    // Cek jika menerima chat pesan baru "/led3_off" maka led 3 harus dimatikan
    if (text == "/led3_off") {
      bot.sendMessage(chat_id, "LED 3 state set to OFF", "");
      ledState3 = LOW;
      digitalWrite(pin_Led_3, ledState3);
    }
    
    // Cek jika menerima chat pesan baru "/led4_on" maka led 4 harus dinyalakan
    if (text == "/led4_on") {
      bot.sendMessage(chat_id, "LED 4 state set to ON", "");
      ledState4 = HIGH;
      digitalWrite(pin_Led_4, ledState4);
    }
    
    // Cek jika menerima chat pesan baru "/led4_off" maka led 4 harus dimatikan
    if (text == "/led4_off") {
      bot.sendMessage(chat_id, "LED 4 state set to OFF", "");
      ledState4 = LOW;
      digitalWrite(pin_Led_4, ledState4);
    }
    
    // Cek jika menerima chat pesan baru "/relay_on" maka RELAY harus dinyalakan
    if (text == "/relay_on") {
      bot.sendMessage(chat_id, "RELAY state set to HIGH", "");
      relaystate = HIGH;
      digitalWrite(pin_Relay, relaystate);
    }
    
    // Cek jika menerima chat pesan baru "/relay_off" maka RELAY harus dimatikan
    if (text == "/relay_off") {
      bot.sendMessage(chat_id, "RELAY state set to LOW", "");
      relaystate = LOW;
      digitalWrite(pin_Relay, relaystate);
    }

    // Cek jika menerima chat pesan baru "/cekledrelay" maka akan dikirim ke telegram kondisi LED 3 dan LED 4 
    if (text == "/cekledrelay") {
      if (digitalRead(pin_Led_3)){
        bot.sendMessage(chat_id, "LED 3 is ON", "");
      }
      else{
        bot.sendMessage(chat_id, "LED 3 is OFF", "");
      }
      if (digitalRead(pin_Led_4)){
        bot.sendMessage(chat_id, "LED 4 is ON", "");
      }
      else{
        bot.sendMessage(chat_id, "LED 4 is OFF", "");
      }
      if (digitalRead(pin_Relay)){
        bot.sendMessage(chat_id, "RELAY is HIGH", "");
      }
      else{
        bot.sendMessage(chat_id, "RELAY is LOW", "");
      }
    }

    // Cek jika menerima chat pesan baru "/cekruangan" maka akan dikirim ke telegram kondisi LED 3 dan LED 4 
    if (text == "/cekruangan") {
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
      
      // Membungkus data Kondisi Ruangan yang harus ditampilkan di Telegram
      String sendKondisi = "Kondisi Ruangan " + from_name + " saat ini :\n";
      sendKondisi += "Kelembapan : " + String(h) + " % \n";
      sendKondisi += "Suhu : " + String(t) + " °C | ";
      sendKondisi += String(f) + " °F";
      sendKondisi += "HeatIndex : " + String(hic) + " °C | ";
      sendKondisi += String(hif) + " °F";
      bot.sendMessage(chat_id, sendKondisi, "");
    }
  }
}