/* ==================
  TrainWare
  Potensiometer Read Code  
=================== */

// Mendefinisikan pin Potensiometer pada ESP32
#define pin_Pot 36

// Mendefinisikan pin LED 4 pada ESP32
#define pin_Led_4   2

// Membuat Fungsi MAP untuk mengatur nilai Minimal & Maksimal (Re-scale)
float floatMap(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void setup() {
  // Inisialisasi Serial dengan baudrate 115200
  Serial.begin(115200);

  // Inisialisasi Pin 4 menjadi OUTPUT
  pinMode(pin_Led_4, OUTPUT);
}

void loop() {
  // Membaca Nilai Input Analog pada Pin GPIO-36
  // Lalu menyimpannya dalam variable "analogValue"
  int analogValue = analogRead(pin_Pot);
  // Rescale Nilai yang dibaca dari ADC (0-4095 menjadi 0-3,3V)
  float voltage = floatMap(analogValue, 0, 4095, 0, 3.3);

  // Mencetak Nilai Mentah ADC yang didapat (0-4095)
  Serial.print("Analog: ");
  Serial.print(analogValue);

  // Mencetak Nilai Hasil fungsi MAP / Re-Scale (0-3,3V)
  Serial.print(", Voltage: ");
  Serial.println(voltage);

  // Rescale Nilai Input Analog menjadi PWM 0-255
  int pwm = map(analogValue, 0, 4095, 0, 255);

  // Fungsi Control LED 4 untuk Dimming
  analogWrite(pin_Led_4, pwm);

  // Jeda 1 Detik 
  delay(1000);
}