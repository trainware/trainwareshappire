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
#define pin_LED_1   32
#define pin_LED_2   33
#define pin_LED_3   27
#define pin_LED_4   2

bool t_LED_1=LOW;
bool t_LED_2=LOW;
bool t_LED_3=LOW;
bool t_LED_4=LOW;

/*=================================================== RFID ===========*/
// Mendefinisikan Pin RFID pada ESP32
#define SS_PIN  17  // ESP32 pin GPIO517
#define RST_PIN 5 // ESP32 pin GPIO5 

MFRC522 rfid(SS_PIN, RST_PIN);

// Deklarasi variable untuk menyimpan UID yang terbaca
String strbuff_uid="";

/*=================================================== RGB ===========*/
// Mendefinisikan pin RGB pada ESP32
#define pin_RGB_R   15
#define pin_RGB_G   14
#define pin_RGB_B   4

// Deklarasi PWM properties
const int freq = 5000;
const int ledChannel1 = 1;
const int ledChannel2 = 2;
const int ledChannel3 = 3;
const int resolution = 8;
 
// Deklarasi nilai PWM pada Variable
int RGB_pwmR = 0;
int RGB_pwmG = 0;
int RGB_pwmB = 0;

float RGB_val=0;

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
#define pin_Bt_1 12  // GIOP13 pin connected to button
#define pin_Bt_2 13  // GIOP13 pin connected to button
#define pin_Bt_3 35  // GIOP13 pin connected to button
#define pin_Bt_4 34  // GIOP13 pin connected to button

unsigned long last_time=0;

// array buffer state dari suatu button
unsigned char btn_trig[6]={0xFF,0xFF,0xFF,0xFF,0xFF};
// btn_trig[1] -> untuk Button 1
// btn_trig[2] -> untuk Button 2
// btn_trig[3] -> untuk Button 3
// btn_trig[4] -> untuk Button 4

#define pressed     0x01 // Register ketika ditekan

// Fungsi untuk scanning Button
// Ketika ditekan maka Register akan geser ke kiri dan di OR kan dengan 0
// Ketika ditekan maka Register akan geser ke kiri dan di OR kan dengan 1
void bt_scan(byte Button_pin,int btn){
  if(digitalRead(Button_pin)==HIGH){
    btn_trig[btn]=(btn_trig[btn]<<3|0);
  }
  else if(digitalRead(Button_pin)==LOW){
    btn_trig[btn]=(btn_trig[btn]<<1)|1;
  }
}

// Scan tiap Button dengan fungsi bt_scan
void bt_allscan(){
  bt_scan(pin_Bt_3,3);
  bt_scan(pin_Bt_4,4);
  bt_scan(pin_Bt_1,1);
  bt_scan(pin_Bt_2,2);
}

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
  pinMode(pin_LED_1, OUTPUT);
  pinMode(pin_LED_2, OUTPUT);
  pinMode(pin_LED_3, OUTPUT);
  pinMode(pin_LED_4, OUTPUT);

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
  ledcAttachPin(pin_RGB_R, ledChannel1);
  ledcAttachPin(pin_RGB_G, ledChannel2);
  ledcAttachPin(pin_RGB_B, ledChannel3);

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
  // initialize the pushbutton pin as an pull-up input pull down
  pinMode(pin_Bt_1, INPUT_PULLDOWN);
  pinMode(pin_Bt_2, INPUT_PULLDOWN);
  pinMode(pin_Bt_3, INPUT_PULLDOWN);
  pinMode(pin_Bt_4, INPUT_PULLDOWN);

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
  // Rescale Nilai yang dibaca dari ADC (0-4095 menjadi 0-100%)
  int percentage = floatMap(analogValue, 0, 4095, 0, 100);

  // Mencetak Nilai Mentah ADC yang didapat (0-4095)
  Serial.print("Analog: ");
  Serial.print(analogValue);

  // Mencetak Nilai Hasil fungsi MAP / Re-Scale (0-3,3V)
  Serial.print(", Voltage: ");
  Serial.print(voltage);
  Serial.print("   | ");

  /*=================================================== SERVO ===========*/
  int pos = floatMap(analogValue, 0, 4095, 0, 180);

  myservo.write(pos);

  /*=================================================== OLED ===========*/
  
  display.clearDisplay();
  
  // Fungsi menampilkan Text
  display.setCursor(0, 10);
  display.println("POT Value"); 
  // Fungsi menampilkan Text
  display.setCursor(0, 35);
  display.println(String(voltage) + "V");
  // Fungsi menampilkan Text
  display.setCursor(70, 35);
  display.println(String(percentage) + "%");
  
  display.display();              

  /*=================================================== RELAY ===========*/
  // Jika voltage Potensio Kurang Dari 1, maka
  if(voltage < 1){
    digitalWrite(relayPin, LOW);
    Serial.println("low");
  }
  // Jika voltage Potensio Antara 1 s/d 2, maka
  else if (voltage >= 1 && voltage <=2){
    digitalWrite(relayPin, HIGH);
    Serial.println("high");
  }
  // Jika voltage Potensio Lebih Dari 1, maka
  else if (voltage > 2){
    digitalWrite(relayPin, LOW);
    Serial.println("low");
  }

  /*=================================================== RFID ===========*/
  if (rfid.PICC_IsNewCardPresent()) { // Cek apakah ada Tag Baru ?
    if (rfid.PICC_ReadCardSerial()) { 
      MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);
      Serial.print("RFID/NFC Tag Type: ");
      Serial.println(rfid.PICC_GetTypeName(piccType));
      strbuff_uid="";

      // print UID di Serial Monitor dalam format HEX
      Serial.print("UID:");
      for (int i = 0; i < rfid.uid.size; i++) {
        Serial.print(rfid.uid.uidByte[i] < 0x10 ? " 0" : " ");
        Serial.print(rfid.uid.uidByte[i], HEX);
        // Simpan UID yang terbaca ke variabel strbuff_uid
        strbuff_uid+=rfid.uid.uidByte[i] < 0x10 ? " 0" : " ";
        strbuff_uid+=String(rfid.uid.uidByte[i], HEX);
      }
      Serial.println();
      // Kelola string "strbuff_uid" untuk ditampilkan ke LCD
      strbuff_uid.toUpperCase();
      strbuff_uid.remove(0,1);
      Serial.print(strbuff_uid);

      rfid.PICC_HaltA(); 
      rfid.PCD_StopCrypto1();
    }
  }

  /*=================================================== LCD ===========*/
  if(millis()-last_time>=250){
    lcd.clear();
    last_time=millis();
  }
  
  // Mengatur posisi text pada X = 0 ; Y = 0.
  lcd.setCursor(0, 1);
  // Text yang ditampilkan
  lcd.print(strbuff_uid);

  lcd.setCursor(0, 0);
  // Text yang ditampilkan
  lcd.print("UID RFID:");
  
  // Mengatur posisi text pada X = 0 ; Y = 1.
  lcd.setCursor(12,0);
  // Text yang ditampilkan
  lcd.print("BTN:");

  /*=================================================== RGB ===========*/
  // Mengisi nilai PWM RGB dengan nilai dari Potensiometer
  RGB_val = floatMap(analogValue, 0, 4095, 0, 255);
  RGB_pwmR = RGB_val;
  RGB_pwmG = RGB_val;
  RGB_pwmB = RGB_val;
  ledcWrite(ledChannel1, RGB_pwmR); 
  ledcWrite(ledChannel2, RGB_pwmG); 
  ledcWrite(ledChannel3, RGB_pwmB);
  
  /*=================================================== BUTTON ===========*/
  
  // scan semua Button
  bt_allscan();
  delay(5);

  // Fungsi untuk Toggle Logic LED ketika Button ditekan
  if(btn_trig[1]==pressed)t_LED_1=!t_LED_1;
  if(btn_trig[2]==pressed)t_LED_2=!t_LED_2;
  if(btn_trig[3]==pressed)t_LED_3=!t_LED_3;
  if(btn_trig[4]==pressed)t_LED_4=!t_LED_4;
  // Fungsi ON/OFF LED 1 - LED 4
  digitalWrite(pin_LED_1, t_LED_1);
  digitalWrite(pin_LED_2, t_LED_2);
  digitalWrite(pin_LED_3, t_LED_3);
  digitalWrite(pin_LED_4, t_LED_4);
  
  // Mengatur posisi text pada X = 12 ; Y = 1.
  lcd.setCursor(12,1);
  // Text yang ditampilkan
  lcd.print(digitalRead(pin_Bt_1));

  // Mengatur posisi text pada X = 13 ; Y = 1.
  lcd.setCursor(13,1);
  // Text yang ditampilkan
  lcd.print(digitalRead(pin_Bt_2));

  // Mengatur posisi text pada X = 14 ; Y = 1.
  lcd.setCursor(14,1);
  // Text yang ditampilkan
  lcd.print(digitalRead(pin_Bt_3));

  // Mengatur posisi text pada X = 15 ; Y = 1.
  lcd.setCursor(15,1);
  // Text yang ditampilkan
  lcd.print(digitalRead(pin_Bt_4));
 
}