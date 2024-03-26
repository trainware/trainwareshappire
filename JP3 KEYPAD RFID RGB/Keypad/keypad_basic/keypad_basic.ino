/* ==================
  TrainWare
  KEYPAD Read Code  
=================== */

// Inisialisasi Library
#include <Keypad.h>

// Definisikan Jumlah Baris (ROW) & Kolom (COL)
#define ROW_NUM     4 // empat rows
#define COL_NUM     4 // empat columns

// Inisialisai Variable Array Keys 
// yang berisii Karakter dalam Keypad
char keys[ROW_NUM][COL_NUM] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

// Inisialisasi Pin yang digunakan Keypad pada ESP32
byte pin_Rows[ROW_NUM]      = {17, 4, 14, 15};  // GPIO17, GPIO4, GPIO14, GPIO15 connect to the row pins
byte pin_Column[COL_NUM]    = {23, 19, 18, 5};  // GPIO23, GPIO19, GPIO18, GPIO5 connect to the column pins

// Alliasing Library Keypad -> keypad
Keypad keypad = Keypad( makeKeymap(keys), pin_Rows, pin_Column, ROW_NUM, COL_NUM );

void setup() {
  // Start serial dengan baudrate 115200
  Serial.begin(115200);
}

void loop() {
  // Variable penampung Tombol Keypad yang ditekan
  char key = keypad.getKey(); // Hasinya bisa berupa : 1 atau 4 atau A atau B

  // Jika nilai key = true, 
  // maka Akan ditampilkan tombol yang ditekan melalui Serial Monitor
  if (key) {
    Serial.println(key);
  }
}
