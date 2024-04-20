#define THINGER_SERIAL_DEBUG

#include <ThingerESP32.h>

#define USERNAME            "fendiard"
#define DEVICE_ID           "esp32_TrainWare"
#define DEVICE_CREDENTIAL   "4ZNfQacl854idM0m"

#define SSID            "NKRI1"
#define SSID_PASSWORD   "indonesia1968"

ThingerESP32 thing(USERNAME, DEVICE_ID, DEVICE_CREDENTIAL);

// Mendefinisikan pin LED-3 dan LED-4 pada ESP32
#define pin_Led_3   27
#define pin_Led_4   2

// Inisialisasi Library Servo.h
#include <Servo.h>

// mendefinisikan pin Servo pada ESP32
#define pin_Servo  26

// Mendefinisikan pin Flame Sensor pada ESP32
#define pin_Flame  39

// Alliasing library Servo menjadi myservo
Servo myservo;  
// Anda dapat menambahkan servo hingga 12 buah
// Servo myservo2; // Uncomment ini jika ingin menambahkan hingga 2 servo  

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

// Inisialisasi Variable pos (posisi servo)
int pos = 0; 

int aux_position=0;
int new_position=0;

void setup() {

  Serial.begin(115200);

  pinMode(pin_Led_3, OUTPUT);
  pinMode(pin_Led_4, OUTPUT);

  // Inisialisasi start Servo 
  myservo.attach(pin_Servo);

  // meng Set pin flame sensor pada ESP32 sebagai INPUT
  pinMode(pin_Flame, INPUT);

  // Mengatur Pin Trigger dan Echo ke Mode OUTPUT
  pinMode(pin_Trig, OUTPUT); 
  pinMode(pin_Echo, INPUT); 

  thing.add_wifi(SSID, SSID_PASSWORD);

  thing["Ctrl_LED_4"] << digitalPin(2);
  thing["Ctrl_LED_3"] << digitalPin(27);
  thing["Ctrl_Servo"]<<[](pson &in){
    if(in.is_empty()){
      in = aux_position;
    }else{
      new_position = in;
      aux_position= (int)new_position;   
    }
    Serial.println(aux_position);
    myservo.write(aux_position);
  };  

  thing["millis"] >> outputValue(millis());
  thing["Read_Flame"] >> outputValue(digitalRead(pin_Flame));


  // more details at http://docs.thinger.io/arduino/
}

void loop() {
  thing.handle();
}