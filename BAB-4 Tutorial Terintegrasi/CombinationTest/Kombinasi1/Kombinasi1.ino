
// inisialisasi library RFID
#include <SPI.h>
#include <MFRC522.h>

// inisialisasi library LCD
#include "LiquidCrystal_I2C.h"

// inisialisasi library OLED
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

/*=================================================== RELAY ===========*/
// mendefinisikan pin Relay pada ESP32
#define relayPin  25

/*=================================================== US ===========*/
// Mendefinisikan Pin GPIO yang digunakan untuk US (Ultrasonik)
#define trigPin   32
#define echoPin   33

// mendefinisikan nilai kecepatan suara (cm/us)
#define SOUND_SPEED 0.034

// Mendefinisikan nilai Variable Pengali CM ke Inchi
#define CM_TO_INCH 0.393701

// Mendeklarasikan variable durasi, jarak dalam CM dan Inchi
long durasi;
float jarakCM;
float jarakINCH;

/*=================================================== RFID ===========*/
// Mendefinisikan Pin RFID pada ESP32
#define SS_PIN  17  // ESP32 pin GPIO517
#define RST_PIN 5 // ESP32 pin GPIO5 

MFRC522 rfid(SS_PIN, RST_PIN);

/*=================================================== RGB ===========*/
// Mendefinisikan pin RGB pada ESP32
#define RGB_R   4
#define RGB_G   14
#define RGB_B   15

// Deklarasi PWM properties
const int freq = 5000;
const int ledChannel1 = 0;
const int ledChannel2 = 1;
const int ledChannel3 = 2;
const int resolution = 8;
 
// Deklarasi nilai PWM pada Variable
int RGB_pwmR = 0;
int RGB_pwmG = 0;
int RGB_pwmB = 0;


/*=================================================== FLAME ===========*/
// Mendefinisikan pin Flame Sensor pada ESP32
// #define flameAnalogPin  4
#define flameDigPin  39


/*=================================================== LCD ===========*/
// atur jumlah Baris-Kolom LCD yang digunakan 
int lcdColumns = 16;
int lcdRows = 2;

// address I2C LCD : 0x27.
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);  


/*=================================================== OLED ===========*/
// Mendefinisikan spesifikasi OLED yang digunakan
#define SCREEN_WIDTH 128 // lebar OLED, dalam pixels
#define SCREEN_HEIGHT 64 // panjang OLED, dalam pixels

// Deklarasi OLED SSD1306 terhubung ke I2C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

/*=================================================== GAS ===========*/
// Mendefinisikan pin Analog gas Sensor MQ-2 pada ESP32
#define gasPin    34

/*=================================================== BUZZER ===========*/
// mendefinisikan pin Buzzer pada ESP32
#define buzzerPin  26

void setup() {
  
  // Inisialiasasi Serial, dengan baudrate 115200
  Serial.begin(115200);

  /*=================================================== RELAY ===========*/
  // meng Set pin Relay pada ESP32 sebagai OUTPUT
  pinMode(relayPin, OUTPUT);

  // Mengatur Mode Pin Trigger dan Echo
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 

  /*=================================================== RFID ===========*/

  SPI.begin(); // init SPI bus
  rfid.PCD_Init(); // init MFRC522

  Serial.println("Tap an RFID/NFC tag on the RFID-RC522 reader");

  /*=================================================== RGB ===========*/
  // configure LED PWM functionalitites
  ledcSetup(ledChannel1, freq, resolution);
  ledcSetup(ledChannel2, freq, resolution);
  ledcSetup(ledChannel3, freq, resolution);
  
  // attach the channel to the GPIO to be controlled
  ledcAttachPin(RGB_R, ledChannel1);
  ledcAttachPin(RGB_G, ledChannel2);
  ledcAttachPin(RGB_B, ledChannel3);

  /*=================================================== FLAME ===========*/
  // meng Set pin flame sensor pada ESP32 sebagai INPUT
  pinMode(flameDigPin, INPUT);

  /*=================================================== LCD ===========*/
  // Inisialisasi LCD
  lcd.init();
  // Fungsi menyalakan backlight LCD
  lcd.backlight();

  /*=================================================== OLED ===========*/
  // Fungsi untuk Start OLED SSD1306, Jika gagal maka ada keterangan "SSD1306 Allocation failed"
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

  // jeda 2 detik
  delay(2000);

  // Menghapus tampilan yang ada di OLED
  display.clearDisplay();

  // Mengatur ukuran Text yang tertampil di OLED sebesar 1
  display.setTextSize(2.5);

  // Mengatur warna Text yang tertampil di OLED, warna putih
  display.setTextColor(WHITE);

  /*=================================================== BUZZER ===========*/
  // meng Set pin buzzer pada ESP32 sebagai OUTPUT
  pinMode(buzzerPin, OUTPUT);
}

void loop() {

  
  /*=================================================== US ===========*/
  digitalWrite(trigPin, LOW);

  // Jeda 2 Mikrodetik
  delayMicroseconds(2);
  
  // Meng set HIGH pada Pin Trigger selama 10 mikrodetik
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Membaca nilai pin ECHO yang mendapat sinyal dari gelombang pantul
  durasi = pulseIn(echoPin, HIGH);
  
  // Menghitung jarak dari nilai pin ECHO
  jarakCM = durasi * SOUND_SPEED/2;
  
  // Mengkonvert menjadi Inchi (Optional)
  jarakINCH = jarakCM * CM_TO_INCH;
  
  // Menampilkan hasil melalui Serial Monitor
  Serial.print("Distance (cm): ");
  Serial.println(jarakCM);
  Serial.print("Distance (inch): ");
  Serial.println(jarakINCH);
  
  /*=================================================== RELAY ===========*/
  if(jarakCM < 20){
    // Jika modul Relay Normally Closed
    // Maka arus mengalir pada logic LOW
    digitalWrite(relayPin, LOW);
    Serial.println("low");
  }
  else if (jarakCM >= 20 && jarakCM <=40){
    // Jika modul Relay Normally High
    // Maka arus mengalir pada logic HIGH
    digitalWrite(relayPin, HIGH);
    Serial.println("high");
  }
  else if (jarakCM >= 40 && jarakCM <=60){
    // Jika modul Relay Normally High
    // Maka arus mengalir pada logic HIGH
    digitalWrite(relayPin, HIGH);
    Serial.println("high");
  }

  /*=================================================== RFID ===========*/
  if (rfid.PICC_IsNewCardPresent()) { // new tag is available
      if (rfid.PICC_ReadCardSerial()) { // NUID has been readed
        MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);
        Serial.print("RFID/NFC Tag Type: ");
        Serial.println(rfid.PICC_GetTypeName(piccType));

        // print UID in Serial Monitor in the hex format
        Serial.print("UID:");
        for (int i = 0; i < rfid.uid.size; i++) {
          Serial.print(rfid.uid.uidByte[i] < 0x10 ? " 0" : " ");
          Serial.print(rfid.uid.uidByte[i], HEX);
        }
        Serial.println();

        rfid.PICC_HaltA(); // halt PICC
        rfid.PCD_StopCrypto1(); // stop encryption on PCD
      }
    }

  /*=================================================== RGB ===========*/
  RGB_pwmR = RGB_pwmG = RGB_pwmB = jarakCM;
  if(RGB_pwmR < 0 && RGB_pwmG < 0 && RGB_pwmB < 0){
    RGB_pwmR = RGB_pwmG = RGB_pwmB = 0;
  }
  ledcWrite(ledChannel3, RGB_pwmR);
  ledcWrite(ledChannel1, RGB_pwmG); 
  ledcWrite(ledChannel2, RGB_pwmB); 

  /*=================================================== FLAME SENSOR ===========*/
  // Deklarasi variable pembacaan FlameSensor
  int firesensorDigital = digitalRead(flameDigPin);

  // Menampilkan hasil pembacaan Digital untuk sensor
  Serial.print("Fire Class: ");
  Serial.println(firesensorDigital);

  /*=================================================== LCD ===========*/
  // Mengatur posisi text pada X = 0 ; Y = 0.
  lcd.clear(); 
  lcd.setCursor(0, 0);
  // Text yang ditampilkan
  lcd.print("JarakUS:");
  
  // Mengatur posisi text pada X = 9 ; Y = 0.
  lcd.setCursor(9, 0);
  // Text yang ditampilkan
  lcd.print(jarakCM);
   
  // Mengatur posisi text pada X = 0 ; Y = 1.
  lcd.setCursor(0,1);
  // Text yang ditampilkan
  lcd.print("Flame:");
  
  // Mengatur posisi text pada X = 9 ; Y = 1.
  lcd.setCursor(9,1);
  // Text yang ditampilkan
  lcd.print(firesensorDigital);
  
 
  
  /*=================================================== GAS ===========*/
  // Deklarasi variable untuk menyimpan Nilai Pembacaan sensor Gas
  int gas_Aout = analogRead(gasPin); 

  /*=================================================== OLED ===========*/
  display.clearDisplay();
  display.setCursor(0, 10);
  // Fungsi menampilkan Text
  display.println("Gas Status"); 

  display.setCursor(0, 35);
  // Fungsi menampilkan Text
  display.println(gas_Aout);
  display.display();

  /*=================================================== BUZZER ===========*/
  if(gas_Aout >=1800){
    digitalWrite(buzzerPin, HIGH);
    // Atur nilai berikut untuk durasi on buzzer
  }
  else{
    digitalWrite(buzzerPin, LOW);
    // Atur nilai berikut untuk durasi off buzzer 
  }
  delay(100);
}