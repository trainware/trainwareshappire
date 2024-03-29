/* ==================
  TrainWare
  Push Button Code
  dengan shift register
=================== */

// Mendefinisikan pin BUTTON-1 sampai BUTTON-4 pada ESP32
#define pin_Bt_1 12  // GIOP12 pin connected to button
#define pin_Bt_2 13  // GIOP13 pin connected to button
#define pin_Bt_3 35  // GIOP35 pin connected to button
#define pin_Bt_4 34  // GIOP34 pin connected to button

// array buffer state dari suatu button
unsigned char btn_trig[6]={0xFF,0xFF,0xFF,0xFF,0xFF};
// btn_trig[1] -> untuk Button 1
// btn_trig[2] -> untuk Button 2
// btn_trig[3] -> untuk Button 3
// btn_trig[4] -> untuk Button 4

#define pressed     0x01 // Register ketika ditekan

void setup() {
  // Inisialiasasi Serial, dengan baudrate 115200
  Serial.begin(115200);

  // Meng set Pin Semua BUTTON menjadi Mode INPUT
  pinMode(pin_Bt_1, INPUT_PULLDOWN);
  pinMode(pin_Bt_2, INPUT_PULLDOWN);
  pinMode(pin_Bt_3, INPUT_PULLDOWN);
  pinMode(pin_Bt_4, INPUT_PULLDOWN);
}

void loop() {
  
  // Menampilkan hasil pembacaan button di Serial Monitor
  btn_trig[1]==pressed && Serial.println("Button 1 ditekan");
  btn_trig[2]==pressed && Serial.println("Button 2 ditekan");
  btn_trig[3]==pressed && Serial.println("Button 3 ditekan");
  btn_trig[4]==pressed && Serial.println("Button 4 ditekan");

  bt_allscan();

  delay(5);
}

// Fungsi untuk scanning Button
// Ketika ditekan maka Register akan geser ke kiri dan di OR kan dengan 0
// Ketika ditekan maka Register akan geser ke kiri dan di OR kan dengan 1
void bt_scan(byte Button_pin,int btn){
  if(digitalRead(Button_pin)==HIGH){
    btn_trig[btn]=(btn_trig[btn]<<1|0);
  }
  else if(digitalRead(Button_pin)==LOW){
    btn_trig[btn]=(btn_trig[btn]<<1)|1;
  }
}

// Scan tiap Button dengan fungsi bt_scan
void bt_allscan(){
  bt_scan(pin_Bt_1,1);
  bt_scan(pin_Bt_2,2);
  bt_scan(pin_Bt_3,3);
  bt_scan(pin_Bt_4,4);
}
