/* ==================
  TrainWare
  Push Button Code
=================== */

// Mendefinisikan pin BUTTON-1 sampai BUTTON-4 pada ESP32
#define pin_Bt_1 12  // GIOP13 pin connected to button
#define pin_Bt_2 13  // GIOP13 pin connected to button
#define pin_Bt_3 35  // GIOP13 pin connected to button
#define pin_Bt_4 34  // GIOP13 pin connected to button

void setup() {
  // Inisialiasasi Serial, dengan baudrate 115200
  Serial.begin(115200);

  // Meng set Pin Semua BUTTON menjadi Mode INPUT
  pinMode(pin_Bt_1, INPUT);
  pinMode(pin_Bt_2, INPUT);
  pinMode(pin_Bt_3, INPUT);
  pinMode(pin_Bt_4, INPUT);
}

void loop() {
  
  // Menampilkan hasil pembacaan button di Serial Monitor
  Serial.print(digitalRead(pin_Bt_1));
  Serial.print(digitalRead(pin_Bt_2));
  Serial.print(digitalRead(pin_Bt_3));
  Serial.println(digitalRead(pin_Bt_4));

  // Jeda 100 ms
  delay(100);
}
