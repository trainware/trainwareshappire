/* ==================
  TrainWare
  Rain Sensor Code  
=================== */

// definisi Pin Sensor Hujan
#define pin_A0Rain   35
#define pin_D0Rain   34

void setup() {

  // Inisialisasi Serial dengan baudrate 115200
  Serial.begin(115200);

  // Meng set Pin rainDigital menjadi Mode Input
  pinMode(pin_D0Rain,INPUT);
}

void loop() {

  // Membaca nilai ADC dari sensor Air hujan
  int rainAnalogVal = analogRead(pin_A0Rain);

  // Membaca nilai digital dari sensor Air hujan
  int rainDigitalVal = digitalRead(pin_D0Rain);

  // Menampilkan hasil pembacaan melalui serial monitor
  Serial.print(rainAnalogVal);
  Serial.print("\t");
  Serial.println(rainDigitalVal);

  //jeda 200ms tiap pembacaan Nilai Sensor
  delay(200);
}