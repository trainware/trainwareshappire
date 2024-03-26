/* ==================
  TrainWare
  LCD I2C SENSOR Code  
=================== */

#include "LiquidCrystal_I2C.h"

// atur jumlah Baris-Kolom LCD yang digunakan 
int lcdColumns = 16;
int lcdRows = 2;

// address I2C LCD : 0x27.
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);  

void setup(){
  // Inisialisasi LCD
  lcd.init();
  // Fungsi menyalakan backlight LCD
  lcd.backlight();
}

void loop(){
  // Mengatur posisi text pada X = 0 ; Y = 0
  lcd.setCursor(0, 0);
  // Text yang ditampilkan
  lcd.print("TrainWare say");
  delay(1000); // jeda 1 detik untuk memunculkan text "TrainWare say"
  // Menghapus tampilan LCD 
  lcd.clear();
  // Mengatur posisi text pada X = 0 ; Y = 1
  lcd.setCursor(0,1);
  lcd.print("Hello, World!");
  // Jeda 1 detik untuk menampikan tulisan
  delay(1000);
  lcd.clear(); 
}