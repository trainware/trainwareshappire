/*=================================================== KEYPAD ===========*/
// yang berisii Karakter dalam Keypad
char keys[ROW_NUM][COL_NUM] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

// Alliasing Library Keypad -> keypad
Keypad keypad = Keypad( makeKeymap(keys), pin_Rows, pin_Column, ROW_NUM, COL_NUM );

void read_keypad(){
  // Variable penampung Tombol Keypad yang ditekan
  char key = keypad.getKey(); // Hasinya bisa berupa : 1 atau 4 atau A atau B 

  // Jika nilai key = true, 
  // maka Akan ditampilkan tombol yang ditekan melalui Serial Monitor
  if (key) {
    Serial.println(key);
    lcd_putsxy(9,1, "      ");
    lcd_putsxy(9,1, String(key));
  }
}

/*=================================================== RFID ===========*/
MFRC522 rfid(pin_SS, pin_RST);

void init_rfid(){
  SPI.begin(); // init SPI bus
  rfid.PCD_Init(); // init MFRC522

  Serial.println("Tap an RFID/NFC tag on the RFID-RC522 reader");
}

String buffer="";

void read_rfid(){
  if (rfid.PICC_IsNewCardPresent()) { // new tag is available
    if (rfid.PICC_ReadCardSerial()) { // NUID has been readed
      MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);
      Serial.print("RFID/NFC Tag Type: ");
      Serial.println(rfid.PICC_GetTypeName(piccType));
      buffer="";
      // print UID in Serial Monitor in the hex format
      lcd_putsxy(4,1, "           ");
      Serial.print("UID:");
      for (int i = 0; i < rfid.uid.size; i++) {
        buffer=buffer+ String(rfid.uid.uidByte[i] < 0x10 ? " 0" : " ");
        buffer=buffer+ String(rfid.uid.uidByte[i], HEX);
      }
      buffer.toUpperCase();
      Serial.print(buffer);
      Serial.println();
      lcd_putsxy(3,1, buffer);

      rfid.PICC_HaltA(); // halt PICC
      rfid.PCD_StopCrypto1(); // stop encryption on PCD
    }
  }
}

/*=================================================== RGB ===========*/
const int resolution = 8;
const int freq = 5000;

int rgb_delay=100;
int state_rgb=0;

// Deklarasi nilai PWM pada Variable
int RGB_pwmR = 0;
int RGB_pwmG = 0;
int RGB_pwmB = 0;

void init_rgb(){
   // configure LED PWM functionalitites
  ledcSetup(ledChannel1, freq, resolution);
  ledcSetup(ledChannel2, freq, resolution);
  ledcSetup(ledChannel3, freq, resolution);
  
  // attach the channel to the GPIO to be controlled
  ledcAttachPin(pin_RGB_R, ledChannel1);
  ledcAttachPin(pin_RGB_G, ledChannel2);
  ledcAttachPin(pin_RGB_B, ledChannel3);
}

void cont_rgb(int _RGB_pwmR, int _RGB_pwmG, int _RGB_pwmB){
  ledcWrite(ledChannel3, _RGB_pwmR);
  ledcWrite(ledChannel1, _RGB_pwmG); 
  ledcWrite(ledChannel2, _RGB_pwmB); 
}


byte rgb_phase=0;
void rgb_contrast(int delays){
  unsigned long time_now=millis();


  if(time_now-time_last>=delays){
    rgb_phase++;
    if(rgb_phase>3){rgb_phase=0;}
    time_last=time_now;
  }
  
  if(rgb_phase==1){
    cont_rgb(0,0,255);
  }
  else if(rgb_phase==2){
    cont_rgb(0,255,0);
  }
  else if(rgb_phase==3){
    cont_rgb(255,0,0);
  }
  else if(rgb_phase==0){
    cont_rgb(255,255,255);
  }
}



int rgb_dim=0;

void rgb_dimming(int delays){
  unsigned long time_now=millis();

  if(time_now-time_last>=(delays/50)){
    if(rgb_phase==1){
      rgb_dim++;
      if(rgb_dim>255){rgb_phase=0;}
    }
    else{
      rgb_dim--;
      if(rgb_dim<0){rgb_phase=1;}
    }
    time_last=time_now;
  }
  Serial.println(rgb_dim);
  cont_rgb(rgb_dim,rgb_dim,rgb_dim);
}

long HSBtoRGB(float _hue, float _sat, float _brightness) {
    float red = 0.0;
    float green = 0.0;
    float blue = 0.0;
    
    if (_sat == 0.0) {
        red = _brightness;
        green = _brightness;
        blue = _brightness;
    } else {
        if (_hue == 360.0) {
            _hue = 0;
        }

        int slice = _hue / 60.0;
        float hue_frac = (_hue / 60.0) - slice;

        float aa = _brightness * (1.0 - _sat);
        float bb = _brightness * (1.0 - _sat * hue_frac);
        float cc = _brightness * (1.0 - _sat * (1.0 - hue_frac));
        
        switch(slice) {
            case 0:
                red = _brightness;
                green = cc;
                blue = aa;
                break;
            case 1:
                red = bb;
                green = _brightness;
                blue = aa;
                break;
            case 2:
                red = aa;
                green = _brightness;
                blue = cc;
                break;
            case 3:
                red = aa;
                green = bb;
                blue = _brightness;
                break;
            case 4:
                red = cc;
                green = aa;
                blue = _brightness;
                break;
            case 5:
                red = _brightness;
                green = aa;
                blue = bb;
                break;
            default:
                red = 0.0;
                green = 0.0;
                blue = 0.0;
                break;
        }
    }

    long ired = red * 255.0;
    long igreen = green * 255.0;
    long iblue = blue * 255.0;
    
    return long((ired << 16) | (igreen << 8) | (iblue));
}

int counter = 0;
int numColors = 255;

void rgb_aurora(int delays){
  unsigned long time_now=millis();
  if(time_now-time_last>=(delays/50)){
    float colorNumber = counter > numColors ? counter - numColors: counter;
    
    // Play with the saturation and brightness values
    // to see what they do
    float saturation = 1; // Between 0 and 1 (0 = gray, 1 = full color)
    float brightness = 1; // Between 0 and 1 (0 = dark, 1 is full brightness)
    float hue = (colorNumber / float(numColors)) * 360; // Number between 0 and 360
    long color = HSBtoRGB(hue, saturation, brightness); 
    
    // Get the red, blue and green parts from generated color
    int red = color >> 16 & 255;
    int green = color >> 8 & 255;
    int blue = color & 255;

    counter = (counter + 1) % (numColors * 2);
    cont_rgb(red, green, blue);

    time_last = time_now;
  }
}