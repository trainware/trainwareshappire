/* ==================
  TrainWare
  RTC DS1307 Code  
=================== */

// Memanggil Library RTC_DS1307
#include "RTClib.h"

// Aliasing Library Menjadi DS1307_RTC
RTC_DS1307 DS1307_RTC;

// Inisialisasi Variable Hari 1 Minggu 
char Week_days[7][12] = {"Minggu", "Senin", "Selasa", "Rabu", "Kamis", "Jumat", "Sabtu"};

void setup () {
  // Inisialisasi Serial dengan Baudrate 115200
  Serial.begin(115200);

  // Inisialisasi Start DS1307
  if (!DS1307_RTC.begin()) {
    Serial.println("Couldn't find RTC");
    while(1);
  }

  // Mengatur waktu pada RTC berdasarkan waktu terakhir Compile Time
  DS1307_RTC.adjust(DateTime(F(__DATE__), F(__TIME__)));
}

void loop () {
    // Menyimpan nilai waktu sekarang ke dalam Variabel "DateTime now"
    DateTime now = DS1307_RTC.now();

    // Menampilkan Waktu Sekarang
    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(" (");
    Serial.print(Week_days[now.dayOfTheWeek()]);
    Serial.print(") ");
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();

    /* Anda dapat menggunakan Fungsi Berikut Jika ingin Mengolah Waktu yang ditampilkan */

    // Serial.print(" since midnight 1/1/1970 = ");
    // Serial.print(now.unixtime());
    // Serial.print("s = ");
    // Serial.print(now.unixtime() / 86400L);
    // Serial.println("d");

    // DateTime future (now + TimeSpan(7,12,30,6));

    // Serial.print(" now + 7d + 12h + 30m + 6s: ");
    // Serial.print(future.year(), DEC);
    // Serial.print('/');
    // Serial.print(future.month(), DEC);
    // Serial.print('/');
    // Serial.print(future.day(), DEC);
    // Serial.print(' ');
    // Serial.print(future.hour(), DEC);
    // Serial.print(':');
    // Serial.print(future.minute(), DEC);
    // Serial.print(':');
    // Serial.print(future.second(), DEC);
    // Serial.println();
    // Serial.println();

    delay(2000);
}