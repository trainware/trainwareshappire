#include <Arduino.h>

// inisialisasi library RFID
#include <SPI.h>
#include <MFRC522.h>

// inisialisasi library LCD
#include "LiquidCrystal_I2C.h"

// inisialisasi library OLED
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Inisialisasi Library KEYPAD
#include <Keypad.h>

// Inisialisasi Library RTC_DS1307
#include "RTClib.h"


// Inisialisasi Library Servo.h
#include <Servo.h>


/* =============================================================================================================== JP1 ===========*/

/* JP 1 =================================================== RELAY ===========*/
// mendefinisikan pin Relay pada ESP32
#define pin_Relay  25

/* JP 1 =================================================== PIR ===========*/
// Mendefinisikan pin motionSensor pada ESP32
#define pin_Pir 25

/* =============================================================================================================== JP2 ===========*/

/* JP 2 =================================================== US ===========*/
// Mendefinisikan Pin GPIO yang digunakan 
// untuk US (Ultrasonik)
#define pin_Trig   32
#define pin_Echo   33

/* JP 2 =================================================== LED ===========*/
#define pin_Led_1   32
#define pin_Led_2   33
#define pin_Led_3   27
#define pin_Led_4   2

/* =============================================================================================================== JP3 ===========*/

/* JP 3 =================================================== KEYPAD ===========*/
// Definisikan Jumlah Baris (ROW) & Kolom (COL)
#define ROW_NUM     4 // empat rows
#define COL_NUM     4 // empat columns

// Inisialisasi Pin yang digunakan Keypad pada ESP32
byte pin_Rows[ROW_NUM]      = {17, 4, 14, 15}; // GIOP19, GIOP18, GIOP5, GIOP17 connect to the row pins
byte pin_Column[COL_NUM]    = {23, 19, 18, 5};   // GIOP16, GIOP4, GIOP0, GIOP2 connect to the column pins

/* JP 3 =================================================== RFID ===========*/
// Mendefinisikan Pin RFID pada ESP32
#define pin_SS  17  // ESP32 pin GPIO517
#define pin_RST 5 // ESP32 pin GPIO5

/* JP 3 =================================================== RGB ===========*/
// Mendefinisikan pin RGB pada ESP32
#define pin_RGB_R   4
#define pin_RGB_G   14
#define pin_RGB_B   15

// Deklarasi PWM properties
#define ledChannel1 0
#define ledChannel2 1
#define ledChannel3 2

/* =============================================================================================================== JP4===========*/

/* JP 4 =================================================== POTENSIOMETER ===========*/
// Mendefinisikan pin Potensiometer pada ESP32
#define pin_Pot  39

/* JP 4 =================================================== FLAME ===========*/
// Mendefinisikan pin Flame Sensor pada ESP32
#define pin_Flame  39

/* JP 4 =================================================== FLAME ===========*/
// Mendefinisikan pin Soil Sensor pada ESP32
#define pin_D0Soil  36
#define pin_A0Soil  39

/* =============================================================================================================== JP5===========*/

/* JP 5 =================================================== LCD ===========*/
// address I2C LCD : 0x27.

/* JP 5 =================================================== OLED ===========*/
// Mendefinisikan spesifikasi OLED yang digunakan
#define SCREEN_WIDTH 128 // lebar OLED, dalam pixels
#define SCREEN_HEIGHT 64 // panjang OLED, dalam pixels

/* =============================================================================================================== JP6===========*/

/* JP 6 =================================================== GAS ===========*/
// Mendefinisikan pin Analog gas Sensor MQ-2 pada ESP32
#define pin_A0Gas    34
#define pin_D0Gas    35

/* JP 6 =================================================== BUTTON ===========*/
#define pressed     0x03

#define pin_BtDown  12
#define pin_BtUp    13
#define pin_BtEnter 35
#define pin_BtBack  34

/* JP 6 =================================================== RAIN ===========*/
// definisi Pin Sensor Hujan
#define pin_A0Rain   35
#define pin_D0Rain   34

/* =============================================================================================================== JP7===========*/

/* JP 7 =================================================== BUZZER ===========*/
// mendefinisikan pin Buzzer pada ESP32
#define pin_Buzzer  26

/* JP 7 =================================================== SERVO ===========*/
// mendefinisikan pin Servo pada ESP32
#define pin_Servo  26

