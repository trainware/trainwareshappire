/* ==================
  TrainWare
  Relay Code
=================== */

// mendefinisikan pin Relay pada ESP32
#define pin_Relay  25

void setup() {
  
  // Inisialiasasi Serial, dengan baudrate 115200
  Serial.begin(115200);

  // Meng Set pin Relay pada ESP32 sebagai OUTPUT
  pinMode(pin_Relay, OUTPUT);
}

void loop() {
  // Mengatur LOGIC LOW pada pin Relay selama 5 detik
  // Jika modul Relay Normally Closed
  // Maka arus AC mengalir pada logic LOW
  digitalWrite(pin_Relay, LOW);
  Serial.println("low");
  delay(5000); 
  
  // Mengatur LOGIC HIGH pada pin Relay selama 5 detik
  // Jika modul Relay Normally High
  // Maka arus AC mengalir pada logic HIGH
  digitalWrite(pin_Relay, HIGH);
  Serial.println("high");
  delay(5000);
}