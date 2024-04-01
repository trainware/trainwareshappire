
void setup() {
  
  // Inisialiasasi Serial, dengan baudrate 115200
  Serial.begin(115200);

  gui_changePage();
  /*=================================================== LCD ===========*/
  init_lcd();
  /*=================================================== OLED ===========*/
  init_oled();
  
  /*=================================================== RTC ===========*/
  // Pilih Salah satu
  
  // gunakan ini jika tidak mengkompile lagi setelahnya
  init_rtc(); 
  
  // gunakan ini untuk men set waktu pada RTC sesuai waktu kompile (Sekarang)
  //set_ds1307_TimeCompile();

  /*=================================================== BUTTON ===========*/
  init_button();

  gui_changePage();
}

void loop() {

  // scan button setiap waktu
  bt_allscan();
  bt_test();

  // fungsi menampilkan GUI
  gui_control();
  
  delay(5);
  
}