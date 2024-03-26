/* ==================
  TrainWare
  Gas Sensor MQ-2 Code
=================== */

// Mendefinisikan pin gas Sensor MQ-2 pada ESP32
#define gasPin    34


void setup() {
  // Inisialiasasi Serial, dengan baudrate 115200
  Serial.begin(115200);
}

void loop() {
  // Deklarasi variable untuk menyimpan Nilai Pembacaan sensor Gas
  int gas_Aout = analogRead(gasPin);  
  Serial.print("Gas Sensor: ");  
  Serial.print(gas_Aout);   /*Read value printed*/
  Serial.print("\t");

  // Jika Nilai Analog lebih dari 1800, Maka diangap ada Gas 
  if (gas_Aout > 1800) {    
    // di Tampilkan Text "Gas" pada serial monitor
    Serial.println("Gas");  
  }
  // Namun Jika Nilai Analog kurang dari 1800, Maka diangap tidak ada Gas 
  else {
    // di Tampilkan Text "No Gas" pada serial monitor
    Serial.println("No Gas");
  }

  // Jeda 1 detik, untuk tiap pembacaan
  delay(1000);
}