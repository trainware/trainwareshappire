/* ==================
  TrainWare
  RFID Read Code  
=================== */

#include <SPI.h>
#include <MFRC522.h>

// Mendefinisikan Pin RFID pada ESP32
#define pin_SS  17  // ESP32 pin GPIO17
#define pin_RST 5   // ESP32 pin GPIO5 

MFRC522 rfid(pin_SS, pin_RST);

void setup() {
  // Inisialiasasi Serial, dengan baudrate 9600
  // Kita juga bisa menggunakan baudrate 115200
  Serial.begin(9600);

  // Fungsi meng-Init Fungsi SPI pada ESP-32
  SPI.begin(); 
  // Fungsi meng-Init RFID pada ESP-32
  rfid.PCD_Init(); 
}

void loop() {
  // Fungsi untuk memeriksa Apakah ada kartu baru yang Terdeteksi
  if (rfid.PICC_IsNewCardPresent()) { 
    // Fungsi membaca kartu RFID secara Serial
    if (rfid.PICC_ReadCardSerial()) { 
      MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);
      Serial.print("RFID/NFC Tag Type: ");
      Serial.println(rfid.PICC_GetTypeName(piccType));

      // Menampilkan ID RFID di Serial Monitor
      Serial.print("UID:");
      for (int i = 0; i < rfid.uid.size; i++) {
        Serial.print(rfid.uid.uidByte[i] < 0x10 ? " 0" : " ");
        Serial.print(rfid.uid.uidByte[i], HEX);
      }
      Serial.println();


      rfid.PICC_HaltA(); 
      rfid.PCD_StopCrypto1(); 
    }
  }
}
