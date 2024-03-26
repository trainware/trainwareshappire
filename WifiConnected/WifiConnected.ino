/* ==================
  TrainWare
  Wifi Connected Code  

  Code untuk menghubungkan ESP32 ke jaringan WIFI
=================== */

// Memasukkan Library Wifi.h kedalam program ini
#include "WiFi.h"

// Isikan SSID dan Password Wifi Anda
// disarankan untuk menghindari spasi 
const char * ssid = "Isi Nama/SSID Wifi anda"; 
const char * password = "Masukkan Password";

void setup()
{
    // Inisialisasi Serial baudrate 115200
    Serial.begin(115200);

    // Fungsi untuk menghubungkan ke Wifi
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);

    // Fungsi mengecek apakah Wifi sudah terhubung atau belum
    if (WiFi.waitForConnectResult() != WL_CONNECTED) {
        Serial.println("WiFi Failed");
        while(1) {
            delay(1000);
        }
    }
    else{
      Serial.println("wifi Connected");
    }
}

void loop()
{
    delay(1000);
    Serial.println("wifi Connected");
}
