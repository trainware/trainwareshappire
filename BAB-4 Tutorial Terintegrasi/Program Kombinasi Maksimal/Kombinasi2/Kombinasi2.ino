// inisialisasi keypad
#include <Keypad.h>

// inisialisasi library LCD
#include "LiquidCrystal_I2C.h"

// inisialisasi library OLED
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Inisialisasi Library Servo.h
#include <Servo.h>

/*=================================================== PIR ===========*/
// Mendefinisikan pin motionSensor pada ESP32
#define pin_PIR 25

unsigned long timer_delay_pir=0;

/*=================================================== ADD LED ===========*/
// Mendefinisikan pin LED pada ESP32
#define LED_1   32
#define LED_2   33
#define LED_3   27
#define LED_4   2

/*=================================================== KEYPAD ===========*/

// Definisikan Jumlah Baris (ROW) & Kolom (COL)
#define ROW_NUM     4 // empat rows
#define COL_NUM     4 // empat columns

// Inisialisai Variable Array Keys 
// yang berisii Karakter dalam Keypad
char keys[ROW_NUM][COL_NUM] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

// Inisialisasi Pin yang digunakan Keypad pada ESP32
byte pin_rows[ROW_NUM]      = {17, 4, 14, 15}; // GIOP19, GIOP18, GIOP5, GIOP17 connect to the row pins
byte pin_column[COL_NUM] = {23, 19, 18, 5};   // GIOP16, GIOP4, GIOP0, GIOP2 connect to the column pins

// Alliasing Library Keypad -> keypad
Keypad keypad = Keypad( makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COL_NUM );

/*=================================================== SOIL SENSE ===========*/
// Mendefinisikan pin Soil Sensor pada ESP32
#define soilPinAnalog  36
#define soilPinDigital  39

// Deklarasi Variable Integer "value" dan "value_soil" untuk menyimpan nilai
int value;
int value_soil;

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

/*=================================================== RAIN ===========*/
// definisi Pin Sensor Hujan
#define rainAnalog    35
#define rainDigital   34

/*=================================================== SERVO ===========*/
#define ServoPin  26

// Alliasing library Servo menjadi myservo
Servo myservo;  
// Anda dapat menambahkan servo hingga 12 buah
// Servo myservo2; // Uncomment ini jika ingin menambahkan hingga 2 servo  

// Inisialisasi Variable pos (posisi servo)
int pos = 0; 

void setup() {
  /*=================================================== PIR ===========*/
  // Inisialisasi Serial Port
  Serial.begin(115200);

  // Meng set Pin motionSensor menjadi Mode Input PullUP
  pinMode(pin_PIR, INPUT);

  /*=================================================== ADD LED ===========*/
  // Meng set Pin LED sebagai OUTPUT
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  pinMode(LED_4, OUTPUT);
  
  /*=================================================== SOIL SENSE ===========*/
  pinMode(soilPinDigital, INPUT);  

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

  /*=================================================== RAIN ===========*/
  // Meng set Pin rainDigital menjadi Mode Input
  pinMode(rainDigital,INPUT);

  /*=================================================== SERVO ===========*/
  // Inisialisasi start Servo 
  myservo.attach(ServoPin);

  myservo.write(pos);
  /*=================================================== OLED ===========*/
  display.setCursor(0, 10);
  // Fungsi menampilkan Text
  display.println("Servo:"); 

  display.setCursor(75, 10);
  // Fungsi menampilkan Text
  display.println(0);

  // Fungsi menampilkan Text
  display.setCursor(0, 35);
  display.print("Kosong");

  display.display();              
  delay(15);
}

void loop() {
  // Clear display OLED
  display.clearDisplay();

  /*=================================================== RAIN ===========*/
  // Membaca nilai ADC dari sensor Air hujan
  int rainAnalogVal = analogRead(rainAnalog);

  // Membaca nilai digital dari sensor Air hujan
  int rainDigitalVal = digitalRead(rainDigital);

  // Menampilkan hasil pembacaan melalui serial monitor
  // Serial.print(rainAnalogVal);
  // Serial.print("\t");
  // Serial.println(rainDigitalVal);

  /*=================================================== LCD ===========*/
  // Mengatur posisi text pada X = 0 ; Y = 0.
  lcd.setCursor(0, 0);
  // Text yang ditampilkan
  lcd.print("Moisture:");
  
  // Mengatur posisi text pada X = 9 ; Y = 0.
  lcd.setCursor(10, 0);
  // Text yang ditampilkan
  lcd.print(value);
  lcd.setCursor(14, 0);
  // Text yang ditampilkan
  lcd.print("%");

  // Mengatur posisi text pada X = 0 ; Y = 1.
  lcd.setCursor(0, 1);
  // Text yang ditampilkan
  lcd.print("Rain:");
  
  // Mengatur posisi text pada X = 6 ; Y = 1.
  lcd.setCursor(6, 1);
  // Text yang ditampilkan
  lcd.print(rainAnalogVal);

  /*=================================================== PIR ===========*/
  // fungsi untuk mengambil data pembacaan sensor PIR
  bool state_pir = digitalRead(pin_PIR);
  
  // jika kondisi terbaca = 0, maka serial akan menampilkan 
  // "Motion Tidak Terdeteksi"
  if (state_pir == 0 && (millis()-timer_delay_pir) >= 3000){
    Serial.println("Motion Tidak Terdeteksi");  
    /*=================================================== ADD LED ===========*/
    digitalWrite(LED_1, LOW);
    digitalWrite(LED_2, LOW);
    digitalWrite(LED_3, LOW);
    digitalWrite(LED_4, LOW);
    /*=================================================== OLED ===========*/
    // Fungsi menampilkan Text
    display.setCursor(0, 35);
    display.print("Kosong");
  } 
  // jika kondisi terbaca 1, maka serial akan menampilkan 
  // "Motion Terdeteksi"
  else if (state_pir == 1){
    Serial.println("Motion Terdeteksi");
    /*=================================================== ADD LED ===========*/
    digitalWrite(LED_1, HIGH);
    digitalWrite(LED_2, HIGH);
    digitalWrite(LED_3, HIGH);
    digitalWrite(LED_4, HIGH);
    /*=================================================== OLED ===========*/
    // Fungsi menampilkan Text
    display.setCursor(0, 35);
    display.print("Ada Orang");
    timer_delay_pir=millis();
  }

  /*=================================================== KEYPAD ===========*/
  // Variable penampung Tombol Keypad yang ditekan
  char key = keypad.getKey(); // Hasinya bisa berupa : 1 atau 4 atau atau A atau B

  // Jika nilai key = true, 
  // maka Akan ditampilkan tombol yang ditekan melalui Serial Monitor
  if (key) {
    Serial.println(key);
        
    if(key=='1'){
      pos=0;
    }
    else if(key=='2'){
      pos=30;
    }
    else if(key=='3'){
      pos=60;
    }
    else if(key=='4'){
      pos=90;
    }
    else if(key=='5'){
      pos=120;
    }
    else if(key=='6'){
      pos=150;
    }
    else if(key=='7'){
      pos=180;
    }
    myservo.write(pos);
  }
  /*=================================================== OLED ===========*/
  display.setCursor(0, 10);
  // Fungsi menampilkan Text
  display.println("Servo:"); 

  display.setCursor(75, 10);
  // Fungsi menampilkan Text
  display.println(pos);             
  delay(15);
  display.display(); 

  /*=================================================== SOIL SENSE ===========*/
  // Fungsi mengambil data Analog Soil Sensor dengan ADC
  value_soil = analogRead(soilPinAnalog);

  // Rescale data ADC dari Soil Sensor
  // Rescale nilai 550-0 menjadi 0-100
  value = map(value_soil,4095,0,0,100);
  Serial.print("Soil Raw Data : ");
  Serial.print(value_soil);
  Serial.print("| Moisture : ");
  Serial.print(value);
  Serial.println("%");
  Serial.print("Hasil D0 Soil :");
  Serial.println(digitalRead(soilPinDigital));

  delay(10);
  lcd.clear(); 
}
