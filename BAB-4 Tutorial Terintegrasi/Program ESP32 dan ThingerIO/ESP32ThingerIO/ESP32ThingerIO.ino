/* ==================

  TrainWare
  ESP32 ThingerIO 

  ESP32 terhubung ke Wifi yang memiliki Akses Internet, yang kemudian
  akan terhubung dengan ThingerIO.

  INPUT / ESP32 to ThingerIO :
  •	JP 2 	  : Ultrasonic	  (GPIO-32 & GPIO-33)
  •	JP 4 	  : Potensiometer	(GPIO-36)
  •	JP 4 	  : Flame Sensor	(GPIO-39)
  •	Non JP	: DHT		        (GPIO-16)
  
  OUTPUT / ThingerIO to ESP32
  •	JP 7 	  : Servo 		    (GPIO-26)
  •	Non JP	: LED 4 		    (GPIO-2)
  •	JP1	    : RELAY 		    (GPIO-25)

  Library yang harus diinstall oleh anda:
  thinger.io by Alvaro Luis Bustamante V2.27.0
  dht sensor library by adafruit
  servo.h by Jaroslav Paral V1.0.3

================== */

#define THINGER_SERIAL_DEBUG

#include <ThingerESP32.h>

#define USERNAME            "trainware"         // Isi dengan username Akun Thinger IO Anda
#define DEVICE_ID           "TrainwareShappire" // Isi dengan Device ID yang telah anda isikan saat Membuat Device
#define DEVICE_CREDENTIAL   "STL1iaA_HlvIQ$Ml"  // Isi dengan Device Credential yang telah anda generate random saat Membuat Device

#define SSID                "telkom"
#define SSID_PASSWORD       "indonesia1968"

ThingerESP32 thing(USERNAME, DEVICE_ID, DEVICE_CREDENTIAL);

/*=================================================== LED         ===========*/
// Mendefinisikan pin LED-3 dan LED-4 pada ESP32
#define pin_Led_4   2

/*=================================================== RELAY       ===========*/
// mendefinisikan pin Relay pada ESP32
#define pin_Relay  25

/*=================================================== SERVO       ===========*/

// Inisialisasi Library Servo.h
#include <Servo.h>

// mendefinisikan pin Servo pada ESP32
#define pin_Servo  26

// Alliasing library Servo menjadi myservo
Servo myservo;  
// Anda dapat menambahkan servo hingga 12 buah
// Servo myservo2; // Uncomment ini jika ingin menambahkan hingga 2 servo  

// Inisialisasi Variable pos (posisi servo)
int pos = 0; 

int aux_position_servo=0;
int new_position_servo=0;

/*=================================================== POTENSIOMETER   ===========*/

// Mendefinisikan pin Potensiometer pada ESP32
#define pin_Pot   36

/*=================================================== FLAME SENSE   ===========*/

// Mendefinisikan pin Flame Sensor pada ESP32
#define pin_Flame  39

/*=================================================== DHT           ===========*/

// inisialisasi library DHT Sensor
#include "DHT.h"

// definisi pin yang digunakan ESP32 untuk Sensor DHT
#define pin_DHT 16

// Anda dapat menggunakan Library ini untuk DHT11, DHT22, dan DHT21
// Uncomment salah 1 dari 3, tergantung dari sensor yang digunakan
#define DHTTYPE DHT11       // DHT 11
// #define DHTTYPE DHT22    // DHT 22   (AM2302), AM2321
// #define DHTTYPE DHT21    // DHT 21   (AM2301)

// Aliasing Library DHT -> dht
DHT dht(pin_DHT, DHTTYPE);

/*=================================================== US | Ultrasonic ===========*/

// Mendefinisikan Pin GPIO yang digunakan untuk US (Ultrasonik)
#define pin_Trig   32
#define pin_Echo   33

// Mendefinisikan nilai kecepatan suara (cm/us)
#define SOUND_SPEED 0.034

// Mendefinisikan nilai Variable Pengali CM ke Inchi
#define CM_TO_INCH 0.393701

// Mendeklarasikan variable durasi, jarak dalam CM dan Inchi
long durasi;
float jarakCM;
float jarakINCH;

void setup() {

  Serial.begin(115200);

  // Inisialisasi Set pin LED 4 pada ESP32 sebagai OUTPUT
  pinMode(pin_Led_4, OUTPUT);

  // Meng Set pin Relay pada ESP32 sebagai OUTPUT
  pinMode(pin_Relay, OUTPUT);

  // Inisialisasi start Servo 
  myservo.attach(pin_Servo);

  // Inisialisasi Set pin flame sensor pada ESP32 sebagai INPUT
  pinMode(pin_Flame, INPUT);

  // Inisialisasi Start DHT
  dht.begin();

  // Inisialisasi Set pin Trigger sebagai OUTPUT dan pin Echo sebagai INPUT pada sensor Ultrasonic di ESP32 
  pinMode(pin_Trig, OUTPUT); 
  pinMode(pin_Echo, INPUT); 

  // Fungsi untuk menambahkan SSID dan Password Wifi ke Program ESP32 Thinger.IO
  thing.add_wifi(SSID, SSID_PASSWORD);

  // Fungsi untuk Membaca Data dari Thinger IO
  thing["Ctrl_Relay"] << digitalPin(pin_Relay);
  thing["Ctrl_LED_4"] << digitalPin(pin_Led_4);
  thing["Ctrl_Servo"] << [](pson &in){
    if(in.is_empty()){
      in = aux_position_servo;
    }else{
      new_position_servo = in;
      aux_position_servo = (int)new_position_servo;   
    }
    Serial.println(aux_position_servo);
    myservo.write(aux_position_servo);
  };  

  // Fungsi untuk Mengirimkan Data ke Thinger IO
  thing["Read_Potensio"] >> outputValue(analogRead(pin_Pot));
  thing["Read_Flame"] >> outputValue(!digitalRead(pin_Flame));
  thing["Read_DHT"] >> [](pson& out){
    out["kelembaban"] = dht.readHumidity();
    out["suhu_celcius"] = dht.readTemperature();  
  };
  thing["Read_US"] >> [](pson& out){
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
    Serial.print("Distance (cm): ");
    Serial.println(jarakCM);
    Serial.print("Distance (inch): ");
    Serial.println(jarakINCH);

    out["jarakCM"] = jarakCM;
    out["jarakINCH"] = jarakINCH;  
  };

  thing["millis"] >> outputValue(millis());

}

void loop() {
  // Program hanya berjalan di void Setup()
  thing.handle();
}