/* ==================
  TrainWare
  OLED Display Code  
=================== */

// Memasukkan Library kedalam program ini
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Mendefinisikan spesifikasi OLED yang digunakan
#define SCREEN_WIDTH 128 // lebar OLED, dalam pixels
#define SCREEN_HEIGHT 64 // panjang OLED, dalam pixels

// Deklarasi OLED SSD1306 terhubung ke I2C
Adafruit_SSD1306 OLED(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  // Inisialisasi Serial
  Serial.begin(115200);

  // Fungsi untuk Start OLED SSD1306, Jika gagal maka ada keterangan "SSD1306 Allocation failed"
  if(!OLED.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

  // jeda 2 detik
  delay(2000);

  // Menghapus tampilan yang ada di OLED
  OLED.clearDisplay();

  // Mengatur ukuran Text yang tertampil di OLED sebesar 1
  OLED.setTextSize(2.5);

  // Mengatur warna Text yang tertampil di OLED, warna putih
  OLED.setTextColor(WHITE);

  // Mengatur posisi Text pada X = 0, Y = 10 berdasarkan Pixels
  OLED.setCursor(0, 10);

  // Fungsi menampilkan Text
  OLED.println("TrainWare!");
  OLED.display(); 
}

void loop() {
  OLED.clearDisplay();
  OLED.setCursor(0, 10);
  // Fungsi menampilkan Text
  OLED.println("TrainWare!");
  OLED.display(); 
  delay(1000);
  OLED.clearDisplay();
  OLED.setCursor(0, 20);
  // Fungsi menampilkan Text
  OLED.println("TrainWare!");
  OLED.display(); 
  delay(1000);
  
}