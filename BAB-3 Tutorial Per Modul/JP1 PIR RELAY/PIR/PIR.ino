/* ==================
  TrainWare
  PIR SENSOR Code  
=================== */

// Mendefinisikan pin motionSensor pada ESP32
#define pin_PIR 25

// Deklarasi Variabel Timer untuk PIR
unsigned long timer_delay_pir=0;

void setup() {
  // Inisialiasasi Serial, dengan baudrate 115200
  Serial.begin(115200);

  // Meng set Pin motionSensor menjadi Mode Input PullUP
  pinMode(pin_PIR, INPUT_PULLUP);
}

void loop() {

  // fungsi untuk mengambil data pembacaan sensor PIR
  bool state_pir = digitalRead(pin_PIR);
  
  // jika kondisi terbaca = 0, maka serial akan menampilkan 
  // "Motion Tidak Terdeteksi"
  if (state_pir == 0 && (millis()-timer_delay_pir) >= 3000){
    Serial.println("Motion Tidak Terdeteksi");  
  } 
  // jika kondisi terbaca 1, maka serial akan menampilkan 
  // "Motion Terdeteksi"
  else if (state_pir == 1){
    Serial.println("Motion Terdeteksi");
    timer_delay_pir=millis();
  }
  delay(100);
}