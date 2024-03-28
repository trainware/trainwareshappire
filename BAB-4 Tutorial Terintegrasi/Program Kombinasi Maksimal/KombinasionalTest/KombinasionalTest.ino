
void setup() {
  
  // Inisialiasasi Serial, dengan baudrate 115200
  Serial.begin(115200);

  /*=================================================== LCD ===========*/
  init_lcd();
  /*=================================================== OLED ===========*/
  init_oled();

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
}