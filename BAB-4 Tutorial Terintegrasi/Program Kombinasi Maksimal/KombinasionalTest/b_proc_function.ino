/*=================================================== GENERAL FUNCTION =========*/
// Membuat Fungsi MAP untuk mengatur nilai Minimal & Maksimal (Re-scale)
float floatMap(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

/*=================================================== MENU FUNCTION =========*/
//gui_ = artinya ini fungsi display

void gui_cursorpos(char y){
  lcd.setCursor(0,y);
  lcd.print(">");
}

byte gui_pageNow=0;

void gui_runPage(){

}