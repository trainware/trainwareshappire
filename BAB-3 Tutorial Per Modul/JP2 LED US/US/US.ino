/* ==================
  TrainWare
  ULTRASONIC SENSOR CODE 
=================== */

// Mendefinisikan Pin GPIO yang digunakan untuk US (Ultrasonik)
#define pin_Trig   32
#define pin_Echo   33

// Mendefinisikan nilai kecepatan suara (cm/us)
#define SOUND_SPEED 0.034

// Mendefinisikan nilai Variable Pengali CM ke Inchi
#define CM_TO_INCH 0.393701

// Mendeklarasikan variable durasi, jarak dalam CM dan Inchi
long durasi;
float jarakCM;
float jarakINCH;

void setup() {

  // Inisialisasi Serial baudrate 115200
  Serial.begin(115200); 

  // Mengatur Pin Trigger dan Echo ke Mode OUTPUT
  pinMode(pin_Trig, OUTPUT); 
  pinMode(pin_Echo, INPUT); 
}

void loop() {
  // Meng set LOW pada Pin Trigger selama 2 mikrodetik
  digitalWrite(pin_Trig, LOW);

  // Jeda 2 Mikrodetik
  delayMicroseconds(2);
  
  // Meng set HIGH pada Pin Trigger selama 10 mikrodetik
  digitalWrite(pin_Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pin_Trig, LOW);
  
  // Membaca nilai pin ECHO yang mendapat sinyal dari gelombang pantul
  durasi = pulseIn(pin_Echo, HIGH);
  
  // Menghitung jarak dari nilai pin ECHO
  jarakCM = durasi * SOUND_SPEED/2;
  
  // Mengkonvert menjadi Inchi (Optional)
  jarakINCH = jarakCM * CM_TO_INCH;
  
  // Menampilkan hasil melalui Serial Monitor
  Serial.print("Distance (cm): ");
  Serial.println(jarakCM);
  Serial.print("Distance (inch): ");
  Serial.println(jarakINCH);

  // Jeda 1 detik tiap pengukuran 
  delay(1000);
}