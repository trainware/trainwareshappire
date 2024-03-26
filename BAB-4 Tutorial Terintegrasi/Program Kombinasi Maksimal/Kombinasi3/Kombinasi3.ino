// inisialisasi library RFID
#include <SPI.h>
#include <MFRC522.h>

// inisialisasi library LCD
#include "LiquidCrystal_I2C.h"

// inisialisasi library OLED
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Inisialisasi Library Servo.h
#include <Servo.h>

/*=================================================== RELAY ===========*/
// mendefinisikan pin Relay pada ESP32
#define relayPin  25

/*=================================================== LED ===========*/
// Mendefinisikan pin LED pada ESP32
#define LED_1   32
#define LED_2   33
#define LED_3   27
#define LED_4   2

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


/*=================================================== POTENSIOMETER ===========*/
float floatMap(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

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

/*=================================================== ADD BUTTON ===========*/
// Mendefinisikan pin Button pada ESP32
#define BUTTON_PIN1 12  // GIOP13 pin connected to button
#define BUTTON_PIN2 13  // GIOP13 pin connected to button
#define BUTTON_PIN3 35  // GIOP13 pin connected to button
#define BUTTON_PIN4 34  // GIOP13 pin connected to button

/*=================================================== SERVO ===========*/
#define ServoPin  26

// Alliasing library Servo menjadi myservo
Servo myservo;  
// Anda dapat menambahkan servo hingga 12 buah
// Servo myservo2; // Uncomment ini jika ingin menambahkan hingga 2 servo  

// Inisialisasi Variable pos (posisi servo)
int pos = 0; 

void setup() {
  
  // Inisialiasasi Serial, dengan baudrate 115200
  Serial.begin(115200);

  /*=================================================== RELAY ===========*/
  // meng Set pin Relay pada ESP32 sebagai OUTPUT
  pinMode(relayPin, OUTPUT);

  /*=================================================== ADD LED ===========*/
  // Meng set Pin LED sebagai OUTPUT
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  pinMode(LED_4, OUTPUT);

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

  /*=================================================== ADD BUTTON ===========*/
  // initialize the pushbutton pin as an pull-up input
  pinMode(BUTTON_PIN1, INPUT);
  pinMode(BUTTON_PIN2, INPUT);
  pinMode(BUTTON_PIN3, INPUT);
  pinMode(BUTTON_PIN4, INPUT);

  /*=================================================== SERVO ===========*/
  // Inisialisasi start Servo 
  myservo.attach(ServoPin);

}

void loop() {
  
  /*=================================================== POTENSIOMETER ===========*/
  // Membaca Nilai Input Analog pada Pin GPIO-36
  // Lalu menyimpannya dalam variable "analogValue"
  int analogValue = analogRead(36);
  // Rescale Nilai yang dibaca dari ADC (0-4095 menjadi 0-3,3V)
  float voltage = floatMap(analogValue, 0, 4095, 0, 3.3);

  // Mencetak Nilai Mentah ADC yang didapat (0-4095)
  Serial.print("Analog: ");
  Serial.print(analogValue);

  // Mencetak Nilai Hasil fungsi MAP / Re-Scale (0-3,3V)
  Serial.print(", Voltage: ");
  Serial.println(voltage);

  /*=================================================== RELAY ===========*/
  if(voltage < 1){
    digitalWrite(relayPin, LOW);
    Serial.println("low");
  }
  else if (voltage >= 1 && voltage <=2){
    digitalWrite(relayPin, HIGH);
    Serial.println("high");
  }
  else if (voltage > 2){
    digitalWrite(relayPin, LOW);
    Serial.println("low");
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
  float RGB_val = floatMap(analogValue, 0, 4095, 0, 255);
  RGB_pwmR = RGB_pwmG = RGB_pwmB = RGB_val ;
  ledcWrite(ledChannel3, RGB_pwmR);
  ledcWrite(ledChannel1, RGB_pwmG); 
  ledcWrite(ledChannel2, RGB_pwmB); 

  /*=================================================== LCD ===========*/
  // Mengatur posisi text pada X = 0 ; Y = 0.
  lcd.setCursor(0, 0);
  // Text yang ditampilkan
  lcd.print("Val-Pot:");
  
  // Mengatur posisi text pada X = 9 ; Y = 0.
  lcd.setCursor(9, 0);
  // Text yang ditampilkan
  lcd.print(analogValue);
   
  // Mengatur posisi text pada X = 0 ; Y = 1.
  lcd.setCursor(0,1);
  // Text yang ditampilkan
  lcd.print("Button:");
  
  /*=================================================== BUTTON ===========*/
  // Mengatur posisi text pada X = 8 ; Y = 1.
  lcd.setCursor(8,1);
  // Text yang ditampilkan
  lcd.print(digitalRead(BUTTON_PIN1));

  // Mengatur posisi text pada X = 10 ; Y = 1.
  lcd.setCursor(10,1);
  // Text yang ditampilkan
  lcd.print(digitalRead(BUTTON_PIN2));

  // Mengatur posisi text pada X = 12 ; Y = 1.
  lcd.setCursor(12,1);
  // Text yang ditampilkan
  lcd.print(digitalRead(BUTTON_PIN3));

  // Mengatur posisi text pada X = 14 ; Y = 1.
  lcd.setCursor(14,1);
  // Text yang ditampilkan
  lcd.print(digitalRead(BUTTON_PIN4));
  
  lcd.clear(); 

  /*=================================================== SERVO ===========*/
  int pos = floatMap(analogValue, 0, 4095, 0, 180);

  myservo.write(pos);
  /*=================================================== OLED ===========*/
  
  display.clearDisplay();
  
  // Fungsi menampilkan Text
  display.setCursor(0, 10);
  display.println("Servo"); 

  // Fungsi menampilkan Text
  display.setCursor(0, 20);
  display.println(pos);
  
  display.display();              
  delay(15);



}