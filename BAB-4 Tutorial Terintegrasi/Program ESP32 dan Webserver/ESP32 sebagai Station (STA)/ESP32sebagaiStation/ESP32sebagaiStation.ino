/* ==================
  
  TrainWare
  ESP32 WebServer  Code

  ESP 32 Mode STA (Station Mode)
  
  artinya anda Perlu menyediakan Access Point lagi
  seperti Router, Tethering, dan Lain2.

=================== */

// Memasukkan Library Wifi.h dan WebServer.h kedalam program ini
#include <WiFi.h>
#include <WebServer.h>

#include "LiquidCrystal_I2C.h"

// atur jumlah Baris-Kolom LCD yang digunakan 
int lcdColumns = 16;
int lcdRows = 2;

// address I2C LCD : 0x27.
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows); 

// Isikan SSID dan Password Wifi Anda
// disarankan untuk menghindari spasi 
const char* ssid = "NKRI1";  // Nama network (wifi/router/tether) anda
const char* password = "indonesia1968";  // Password network (wifi/router/tether) anda

// Fungsi untuk start ESP32 sebagai server di Port 80 
WebServer server(80);

// Mendefinisikan pin Potensiometer pada ESP32
#define pin_Pot 36

// Mendefinisikan pin LED 4 pada ESP32
#define pin_Led_4   2
#define pin_Led_3   27

// Inisialisasi Variabel
bool LED1status = LOW;
bool LED2status = LOW;
int analogValue = 0;

void setup() {
  Serial.begin(115200);
  pinMode(pin_Led_4, OUTPUT);
  pinMode(pin_Led_3, OUTPUT);

  Serial.println("Connecting to ");
  Serial.println(ssid);

  // Menghubungkan ESP32 dengan Network anda
  WiFi.begin(ssid, password);

  // Meng-cek apakah ESP32 sudah terhubung Wifi atau belum
  // Jika belum maka akan mengirimkan "." tiap 1 detik ke Serial Monitor

  // Inisialisasi LCD
  lcd.init();
  // Fungsi menyalakan backlight LCD
  lcd.backlight();

  while (WiFi.status() != WL_CONNECTED) {
    lcd.setCursor(0,0);
    lcd.print("Menghubungkan");
    lcd.setCursor(0,1);
    lcd.print("Wifi..");
    delay(1000);
    Serial.print(".");
    lcd.clear();
  }

  lcd.clear();

  // Jika Wifi Terhubung maka ESP32 akan mendapat IP
  // dan dicetak pada Serial Monitor
  Serial.println("");
  Serial.println("WiFi Terhubung ...");
  Serial.print("IP anda: ");  Serial.println(WiFi.localIP());
  lcd.setCursor(0,0);
  lcd.print("IP ESP32 :");
  lcd.setCursor(0,1);
  lcd.print(WiFi.localIP());


  delay(3000);
  
  server.on("/", handle_OnConnect);
  server.on("/led1on", handle_led1on);
  server.on("/led1off", handle_led1off);
  server.on("/led2on", handle_led2on);
  server.on("/led2off", handle_led2off);
  server.onNotFound(handle_NotFound);
  
  server.begin();
  Serial.println("HTTP server started");
}
void loop() {
  if(WiFi.status()== WL_CONNECTED) {
    server.handleClient();
    analogValue = analogRead(pin_Pot);
    Serial.println(analogValue);
    if(LED1status)
    {digitalWrite(pin_Led_4, HIGH);}
    else
    {digitalWrite(pin_Led_4, LOW);}
    
    if(LED2status)
    {digitalWrite(pin_Led_3, HIGH);}
    else
    {digitalWrite(pin_Led_3, LOW);}
  }
  else{
    lcd.setCursor(0,0);
    lcd.print("Menghubungkan");
    lcd.setCursor(0,1);
    lcd.print("Wifi..");
    delay(1000);
    Serial.print(".");
    lcd.clear();
  }
}

void handle_OnConnect() {
  LED1status = LOW;
  LED2status = LOW;
  Serial.println("GPIO2 Status: OFF | GPIO27 Status: OFF");
  Serial.println("Potensio Read Ready");
  server.send(200, "text/html", SendHTML(LED1status,LED2status, analogValue)); 
}

void handle_led1on() {
  LED1status = HIGH;
  Serial.println("GPIO4 Status: ON");
  server.send(200, "text/html", SendHTML(true,LED2status, analogValue)); 
}

void handle_led1off() {
  LED1status = LOW;
  Serial.println("GPIO4 Status: OFF");
  server.send(200, "text/html", SendHTML(false,LED2status, analogValue)); 
}

void handle_led2on() {
  LED2status = HIGH;
  Serial.println("GPIO5 Status: ON");
  server.send(200, "text/html", SendHTML(LED1status,true, analogValue)); 
}

void handle_led2off() {
  LED2status = LOW;
  Serial.println("GPIO5 Status: OFF");
  server.send(200, "text/html", SendHTML(LED1status,false, analogValue)); 
}

void handle_NotFound(){
  server.send(404, "text/plain", "Not found");
}

String SendHTML(uint8_t led1stat,uint8_t led2stat, int analogVal){
    String ptr =R"(
    <!DOCTYPE html> 
    <html>
      <head>
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>LED Control by TrainWare</title>
        <style>
            html { 
                font-family: Helvetica; 
                display: inline-block;
                text-align: center;
            }
            body{
                height: 100%;
                margin-top: 50px;
            }
            h1 {
                color: #444444;
                margin: 10px auto 30px;
            }
    
            #val_pot {
              margin: 10px auto 10px;
            }

            h3 {color: #444444;
                margin-bottom: 50px;
            }
      
            .button {display: block;
                width: 50%;
                height: 100%;
                background-color: #0969ad;
                border: none;
                color: white;
                padding: 13px 30px;
                text-decoration: none;
                font-size: 25px;
                margin: 0px auto 35px;
                cursor: pointer;
                border-radius: 4px;
            }
      
            .button-on {background-color: #0969ad;}
            .button-on:active {background-color: #004678;}
            .button-off {background-color: #4c4c4c;}
            .button-off:active {background-color: #2b2b2b;}
            p {font-size: 14px;color: #888;margin-bottom: 10px;}

            @media(max-width: 1000px){
              h1 {margin: 180px auto 50px;}
            }
            
        </style>
      </head>

      <body>
        <h1>ESP32 WEB SERVER</h1>
        <h3>Sebagai AP (AcessPoint) Mode</h3>
        )";
      
        if(led1stat){
            ptr +="<p>LED1 Status: ON</p><a class=\"button button-off\" href=\"led1off\">OFF</a>\n";
        }
        else{
            ptr +="<p>LED1 Status: OFF<p><a class=\"button button-on\" href=\"led1on\">ON</a>\n";
        }
        
        if(led2stat){
            ptr +="<p>LED2 Status: ON</p><a class=\"button button-off\" href=\"led2off\">OFF</a>\n";
        }
        else{
            ptr +="<p>LED2 Status: OFF<p><a class=\"button button-on\" href=\"led2on\">ON</a>\n";
        }

        ptr +=
        R"(
            <p>Nilai Potensiometer</p>
            <h3 id="val_pot">0</h3>
            <p>Nilai ini akan update hanya saat page direload</p>    
            <p>Gunakan WebSocket untuk bisa mendapat nilai Potensiometer secara realtime</p>
            <h3>by TrainWare</h3>
          </body>

          <script>
            let strDate = )" + String(analogVal) + R"(
            document.getElementById('val_pot').textContent = strDate;
          </script>
          </html>
        )";

  return ptr;
}