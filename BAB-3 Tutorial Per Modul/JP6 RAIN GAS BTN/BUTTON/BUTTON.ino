/* ==================
  TrainWare
  Push Button Code
=================== */

// Mendefinisikan pin BUTTON-1 sampai BUTTON-4 pada ESP32
#define pin_Bt_1 12  // GIOP12 pin connected to button
#define pin_Bt_2 13  // GIOP13 pin connected to button
#define pin_Bt_3 35  // GIOP35 pin connected to button
#define pin_Bt_4 34  // GIOP34 pin connected to button

void setup() {
  // Inisialiasasi Serial, dengan baudrate 115200
  Serial.begin(115200);

  // Meng set Pin Semua BUTTON menjadi Mode INPUT
  pinMode(pin_Bt_1, INPUT_PULLDOWN);
  pinMode(pin_Bt_2, INPUT_PULLDOWN);
  pinMode(pin_Bt_3, INPUT_PULLDOWN);
  pinMode(pin_Bt_4, INPUT_PULLDOWN);
}

void loop() {
  
  // Menampilkan hasil pembacaan button di Serial Monitor
  digitalRead(pin_Bt_1) && Serial.println("Button 1 ditekan");
  digitalRead(pin_Bt_2) && Serial.println("Button 2 ditekan");
  digitalRead(pin_Bt_3) && Serial.println("Button 3 ditekan");
  digitalRead(pin_Bt_4) && Serial.println("Button 4 ditekan");

  // Jeda 100 ms
  delay(100);
}
