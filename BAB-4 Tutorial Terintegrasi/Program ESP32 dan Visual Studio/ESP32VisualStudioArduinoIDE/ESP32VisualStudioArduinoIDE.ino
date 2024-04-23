/* ==================
  
  TrainWare
  ESP32 Visual Studio - UDP Send-Receive Code

  ESP32 tidak sebagai AccessPoint
  
  artinya anda perlu menyediakan Access Point
  seperti Router, Tethering, dan Lain2.
  Projek ini hanya memerlukan Access Point yang sama untuk ESP32 dan PC anda
  Tidak harus terhubung ke Internet

  Pastikan sudah menginstall Visual Studio dan Bisa menjalankan kodenya

  INPUT / ESP32 to ThingerIO :
  •	JP 2 	  : Ultrasonic	  (GPIO-32 & GPIO-33)
  •	JP 4 	  : Potensiometer	(GPIO-36)
  •	Non JP	: DHT		        (GPIO-16)
  
  OUTPUT / ThingerIO to ESP32
  •	JP 7 	  : Servo 		    (GPIO-26)
  •	Non JP	: LED 4 		    (GPIO-2)
  •	Non JP	: LED 3 		    (GPIO-27)

  Display 
  •	JP 5    : LCD I2C

  Library yang harus diinstall oleh anda:
  dht sensor library by adafruit
  servo.h by Jaroslav Paral V1.0.3

=================== */

// Mengincludekan Library Wifi dan WifiUdp ke program ini
#include <WiFi.h>
#include <WiFiUdp.h>

// Inisialisasi Library Servo.h
#include <Servo.h>

// inisialisasi library DHT Sensor
#include "DHT.h"

// Isikan SSID dan Password Wifi Anda
// disarankan untuk menghindari spasi 
const char * ssid = "NKRI1"; // Nama network (wifi/router/tether) anda
const char * pwd  = "indonesia1968"; // Password network (wifi/router/tether) anda

// IP Address dan Port PC Anda
const char * udpAddress = "192.168.100.121"; // Ip Address PC
const int udpPort = 8080;                   // UDP Port PC

// mendefinisikan pin Servo pada ESP32
#define pin_Servo  26

// Mendefinisikan pin Potensiometer pada ESP32
#define pin_Pot 36

// definisi pin yang digunakan ESP32 untuk Sensor DHT
#define pin_DHT 16

// Anda dapat menggunakan Library ini untuk DHT11, DHT22, dan DHT21
// Uncomment salah 1 dari 3, tergantung dari sensor yang digunakan
#define DHTTYPE DHT11   // DHT 11
// #define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

// Mendefinisikan Pin GPIO yang digunakan untuk US (Ultrasonik)
#define pin_Trig   32
#define pin_Echo   33

// Mendefinisikan nilai kecepatan suara (cm/us)
#define SOUND_SPEED 0.034

// Mendefinisikan nilai Variable Pengali CM ke Inchi
#define CM_TO_INCH 0.393701

// Alliasing library Servo menjadi myservo
Servo myservo;  
// Anda dapat menambahkan servo hingga 12 buah
// Servo myservo2; // Uncomment ini jika ingin menambahkan hingga 2 servo  

// Inisialisasi Variable servo_degree (posisi servo)
int servo_degree = 0; 

// Mendeklarasikan variable durasi, jarak dalam CM dan Inchi
long durasi;
float jarakCM;
float jarakINCH;

// Mendefinisikan pin LED 3 dan 4 pada ESP32
#define pin_Led_4   2
#define pin_Led_3   27

// Inisialisasi Variabel
int POT = 0;
int SUHU = 0;
int JARAK = 0;
int LED3status = 0;
int LED4status = 0;

// Variable keperluan Send Data
String DataSend;
int len_send;
char Buffer_Send[15];

String myString;



//create UDP instance
WiFiUDP udp;

// Aliasing Library DHT -> dht
DHT dht(pin_DHT, DHTTYPE);

// Deklarasi Variabel LCD

#include "LiquidCrystal_I2C.h"

// atur jumlah Baris-Kolom LCD yang digunakan 
int lcdColumns = 16;
int lcdRows = 2;

// address I2C LCD : 0x27.
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows); 

void setup(){
  Serial.begin(115200); // to monitor activity

  // Inisialisasi LCD
  lcd.init();
  // Fungsi menyalakan backlight LCD
  lcd.backlight();

  // Inisialisasi start Servo 
  myservo.attach(pin_Servo);

  pinMode(pin_Led_4, OUTPUT);
  pinMode(pin_Led_3, OUTPUT);

  // Mengatur Pin Trigger dan Echo ke Mode OUTPUT
  pinMode(pin_Trig, OUTPUT); 
  pinMode(pin_Echo, INPUT); 

  dht.begin();
  
  // Menghubungkan ESP32 dengan Network anda
  Serial.println("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, pwd);

  while(WiFi.status() != WL_CONNECTED)
  {
    lcd.setCursor(0,0);
    lcd.print("Menghubungkan");
    lcd.setCursor(0,1);
    lcd.print("Wifi..");
    Serial.print("."); delay(500);  
    lcd.clear();
  }

  lcd.clear();

  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  lcd.setCursor(0,0);
  lcd.print("IP ESP32 :");
  lcd.setCursor(0,1);
  lcd.print(WiFi.localIP());
  
  delay(2000);
  
  // Inisialisasi UDP dan memulai transfer data
  udp.begin(udpPort);
}



void loop(){

  // Variabel untuk menyimpan paket yang diterima dari PC
  uint8_t buffer[50];

  memset(buffer, 0, 50);
  
  udp.parsePacket();
  // Memulai menerima paket UDP dengan IP address dan Port PC anda
  udp.beginPacket(udpAddress, udpPort);
  if(udp.read(buffer, 50) > 0){
    myString=(char *)buffer;
    Serial.print("Data Received <- ");
    Serial.println(myString);
    StringOperate(myString);
    
    Serial.println();
  }

  // Fungsi Kontrol Servo dan LED
  myservo.write(servo_degree);
  ctrl_LED();
  // Fungsi Membaca sensor 
  read_POT();
  read_DHT();
  read_US();
  
  // Fungsi untuk mengumpulkan data yang akan dikirimkan ke PC
  DataSend = String(POT) + "#" + String(SUHU) + "#" + String(JARAK) + "#" + String(LED3status) + "#" + String(LED4status);
  Serial.println(DataSend);

  len_send = DataSend.length()+1;
  DataSend.toCharArray(Buffer_Send, len_send);
  // Fungsi untuk mengirimkan data ke PC dengan variabel Buffer Send
  udp.write((uint8_t *) &Buffer_Send, len_send);
  
  udp.endPacket();
  
}

void read_POT(){
  // Fungsi membaca nilai Potensiometer
  POT = analogRead(pin_Pot);
  Serial.print("pot val: ");
  Serial.println(POT);
}

void read_DHT(){
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
  SUHU = t;
}

void read_US(){
  // Meng set LOW pada Pin Trigger selama 2 mikrodetik
  digitalWrite(pin_Trig, LOW);

  // Jeda 2 Mikrodetik
  delayMicroseconds(2);
  
  // Meng set HIGH pada Pin Trigger selama 10 mikrodetik
  digitalWrite(pin_Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pin_Trig, LOW);
  
  // Membaca nilai pin ECHO yang mendapat sinyal dari gelombang pantul
  durasi = pulseIn(pin_Echo, HIGH);
  
  // Menghitung jarak dari nilai pin ECHO
  jarakCM = durasi * SOUND_SPEED/2;
  
  // Mengkonvert menjadi Inchi (Optional)
  jarakINCH = jarakCM * CM_TO_INCH;
  
  // Menampilkan hasil melalui Serial Monitor
  // Serial.print("Distance (cm): ");
  // Serial.println(jarakCM);
  // Serial.print("Distance (inch): ");
  // Serial.println(jarakINCH);
  JARAK = jarakCM;
}

void ctrl_LED(){
  if(LED4status)
  {digitalWrite(pin_Led_4, HIGH);Serial.print("LED 4 High | ");}
  else
  {digitalWrite(pin_Led_4, LOW);Serial.print("LED 4 Low | ");}
  
  if(LED3status)
  {digitalWrite(pin_Led_3, HIGH);Serial.print("LED 3 High | ");}
  else
  {digitalWrite(pin_Led_3, LOW);Serial.print("LED 3 Low | ");}
}

void StringOperate(String input) {
  int comma1 = input.indexOf(',');
  int comma2 = input.indexOf(',', comma1 + 1);

  LED3status = input.substring(0, comma1).toInt();
  LED4status = input.substring(comma1 + 1, comma2).toInt();
  servo_degree = input.substring(comma2 + 1).toInt();

  Serial.print("Value 1: ");
  Serial.println(LED3status);
  Serial.print("Value 2: ");
  Serial.println(LED4status);
  Serial.print("Value 3: ");
  Serial.println(servo_degree);
}