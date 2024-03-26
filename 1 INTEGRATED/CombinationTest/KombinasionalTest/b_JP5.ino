/*=================================================== RTC ===========*/

// Aliasing Library Menjadi DS1307_RTC
RTC_DS1307 DS1307_RTC;

// Inisialisasi Variable Hari 1 Minggu 
char Week_days[7][12] = {"Minggu", "Senin", "Selasa", "Rabu", "Kamis", "Jumat", "Sabtu"};

void init_rtc(){
  // Inisialisasi Start DS1307
  if (!DS1307_RTC.begin()) {
    Serial.println("Couldn't find RTC");
    while(1);
  }
}

void read_ds1307(){
  // Inisialisasi Start DS1307
  if (!DS1307_RTC.begin()) {
    Serial.println("Couldn't find RTC");
    while(1);
  }

  // Mengatur waktu pada RTC berdasarkan waktu terakhir Compile Time
  DS1307_RTC.adjust(DateTime(F(__DATE__), F(__TIME__)));
}

/*=================================================== LCD ===========*/
int lcdColumns = 16;
int lcdRows = 2;
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);  

void init_lcd(){
  // Inisialisasi LCD
  lcd.init();
  // Fungsi menyalakan backlight LCD
  lcd.backlight();
}

void lcd_putsxy(uint8_t x, uint8_t y, String str){
  lcd.setCursor(x,y);
  lcd.print(str);
}

void lcd_erase(char x,char y){
  lcd_putsxy(x,y," ");
}

/*=================================================== OLED ===========*/
Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void init_oled(){
  // Fungsi untuk Start OLED SSD1306, 
  // Jika gagal maka ada keterangan 
  // "SSD1306 Allocation failed"
  if(!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

  // jeda 2 detik
  delay(2000);

  // Menghapus tampilan yang ada di OLED
  oled.clearDisplay();

  // Mengatur ukuran Text yang tertampil di OLED sebesar 1
  oled.setTextSize(2.5);

  // Mengatur warna Text yang tertampil di OLED, warna putih
  oled.setTextColor(WHITE);
}

void oled_putsxy(uint8_t x, uint8_t y, String str){
  // fungsi posisi x y text
  oled.setCursor(x, y);
  // Fungsi menampilkan Text
  oled.println(str);
}