/* ==================
  TrainWare
  RGB Control Code
=================== */

// Mendefinisikan pin RGB pada ESP32
#define pin_RGB_R   4
#define pin_RGB_G   2
#define pin_RGB_B   15

// Mendefinisikan variable ledChannel
#define ledChannel1 0
#define ledChannel2 1
#define ledChannel3 2

// Deklarasi PWM properties
const int freq = 5000;
const int resolution = 8;
 
// Deklarasi nilai PWM pada Variable
int RGB_pwmR = 0; // Isi nilai berikut dari 0 - 255 untuk ke-Terang-an Led RED
int RGB_pwmG = 0; // Isi nilai berikut dari 0 - 255 untuk ke-Terang-an Led GREEN
int RGB_pwmB = 0; // Isi nilai berikut dari 0 - 255 untuk ke-Terang-an Led BLUE

void setup(){
  // configure LED PWM functionalitites
  ledcSetup(ledChannel1, freq, resolution);
  ledcSetup(ledChannel2, freq, resolution);
  ledcSetup(ledChannel3, freq, resolution);
  
  // attach the channel to the GPIO to be controlled
  ledcAttachPin(pin_RGB_R, ledChannel1);
  ledcAttachPin(pin_RGB_G, ledChannel2);
  ledcAttachPin(pin_RGB_B, ledChannel3);
}
 
void loop(){

  // Fungsi untuk Menuliskan Value Terang/Redup pada channel LED tertentu
  ledcWrite(ledChannel1, RGB_pwmR);
  ledcWrite(ledChannel2, RGB_pwmG); 
  ledcWrite(ledChannel3, RGB_pwmB); 
}