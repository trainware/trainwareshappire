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

char read_keypad(){
  return keypad.getKey(); // Hasinya bisa berupa : 1 atau 4 atau atau A atau B
}

/*=================================================== RFID ===========*/
MFRC522 rfid(pin_SS, pin_RST);

void init_rfid(){
  SPI.begin(); // init SPI bus
  rfid.PCD_Init(); // init MFRC522

  Serial.println("Tap an RFID/NFC tag on the RFID-RC522 reader");
}

void read_rfid(){
  if (rfid.PICC_IsNewCardPresent()) { // new tag is available
    if (rfid.PICC_ReadCardSerial()) { // NUID has been readed
      MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);
      Serial.print("RFID/NFC Tag Type: ");
      Serial.println(rfid.PICC_GetTypeName(piccType));

      // print UID in Serial Monitor in the hex format
      Serial.print("UID:");
      for (int i = 0; i < rfid.uid.size; i++) {
        Serial.print(rfid.uid.uidByte[i] < 0x10 ? " 0" : " ");
        Serial.print(rfid.uid.uidByte[i], HEX);
      }
      Serial.println();

      rfid.PICC_HaltA(); // halt PICC
      rfid.PCD_StopCrypto1(); // stop encryption on PCD
    }
  }
}

/*=================================================== RGB ===========*/
const int resolution = 8;
const int freq = 5000;

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

void cont_rgb(uint8_t _RGB_pwmR, uint8_t _RGB_pwmG, uint8_t _RGB_pwmB){
  ledcWrite(ledChannel3, _RGB_pwmR);
  ledcWrite(ledChannel1, _RGB_pwmG); 
  ledcWrite(ledChannel2, _RGB_pwmB); 
}