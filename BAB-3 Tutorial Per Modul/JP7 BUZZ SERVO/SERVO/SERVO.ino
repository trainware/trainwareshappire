/* ==================
  TrainWare
  Servo Control Code  
=================== */

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

void setup() {
  // Inisialisasi start Servo 
  myservo.attach(pin_Servo);
}

void loop() {
  // Fungsi gerakan servo dari 0 derajat hingga 180 derajat
    myservo.write(0);              
    delay(2000);
    myservo.write(180);              
    delay(2000);                      
}