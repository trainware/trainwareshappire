/* ==================
  TrainWare
  Soil Sensor Code
=================== */

// Mendefinisikan pin Soil Sensor pada ESP32
#define pin_D0Soil  39
#define pin_A0Soil  36

// Deklarasi Variable Integer "value" untuk menyimpan nilai
int value;
 
void setup()
{
  
  // Inisialisasi Serial, dengan baudrate 115200
  Serial.begin(115200);

  // Meng set Pin SOIL Digital (D0) menjadi MODE INPUT
  pinMode(pin_D0Soil, INPUT);
  // Untuk Pin Analog tidak perlu di set MODE Pinnya

}
 
void loop()
{
  // Fungsi mengambil data Analog Soil Sensor dengan ADC
  value = analogRead(pin_A0Soil);

  // Rescale data ADC dari Soil Sensor
  // Rescale nilai 4095-0 menjadi 0-100 sebagai percentage (%)
  value = map(value,4095,0,0,100);
  Serial.print("Moisture : ");
  Serial.print(value);
  Serial.println("%");
  Serial.print(" Hasil D0 :");
  Serial.println(digitalRead(pin_D0Soil));

  // Jeda 1 detik
  delay(500);
}