/* ==================
  TrainWare
  Wifi Scanning Code  

  Code untuk mencari jaringan yang terdeteksi disekitar ESP32
=================== */

// Memasukkan Library Wifi.h kedalam program ini
#include "WiFi.h"

void setup() 
{
  // Inisialisasi Serial baudrate 115200
  Serial.begin(115200);

  // Fungsi men-disconnect jaringan yang sedang connect ke ESP32
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);

  Serial.println("Setup done");
}

void loop() {

  // Memulai scanning Wifi
  Serial.println("scan start");

  // Mengecek Jumlah jaringan yang terdeteksi
  int n = WiFi.scanNetworks();
  Serial.println("scan done");
  if (n == 0) {
      Serial.println("no networks found");
  } else {
    Serial.print(n);
    Serial.println(" networks found");
    for (int i = 0; i < n; ++i) {
      // Mencetak SSID dan RSSI yang terdeteksi
      Serial.print(i + 1);
      Serial.print(": ");
      Serial.print(WiFi.SSID(i));
      Serial.print(" (");
      Serial.print(WiFi.RSSI(i));
      Serial.print(")");
      Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN)?" ":"*");
      delay(10);
    }
  }
  Serial.println("");

  // Jeda 5 detik untuk melakukan scanning selanjutnya.
  delay(5000);
}