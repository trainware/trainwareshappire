/* ==================
  
  TrainWare
  ESP32 WebServer  Code

  ESP 32 sebagai AccessPoint
  
  artinya anda tidak perlu menyediakan Access Point lagi
  seperti Router, Tethering, dan Lain2.

=================== */

// Memasukkan Library Wifi.h dan WebServer.h kedalam program ini
#include <WiFi.h>
#include <WebServer.h>

// Isikan SSID dan Password Wifi Anda
// disarankan untuk menghindari spasi 
const char* ssid = "TrainWareESP32";  // Isi Nama network yang ingin dibuat
const char* password = "thankyou";  // Isi password untuk network anda

// Ip berikut tidak perlu diubah
IPAddress local_ip(192,168,1,1);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);

// Fungsi untuk start ESP32 sebagai server di Port 80 
WebServer server(80);

// Mendefinisikan pin Potensiometer pada ESP32
#define pin_Pot 36

// Mendefinisikan pin LED 4 pada ESP32
#define pin_Led_4   2
#define pin_Led_3   27

// Inisialisasi Variabel
bool LED4status = LOW;
bool LED3status = LOW;
int analogValue = 0;

void setup() {
  Serial.begin(115200);
  pinMode(pin_Led_4, OUTPUT);
  pinMode(pin_Led_3, OUTPUT);

  WiFi.softAP(ssid, password);
  WiFi.softAPConfig(local_ip, gateway, subnet);
  delay(100);

  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP); 
  delay(2000);
  
  server.on("/", handle_OnConnect);
  server.on("/LED4on", handle_LED4on);
  server.on("/LED4off", handle_LED4off);
  server.on("/LED3on", handle_LED3on);
  server.on("/LED3off", handle_LED3off);
  server.onNotFound(handle_NotFound);
  
  server.begin();
  Serial.println("HTTP server started");
}
void loop() {
  server.handleClient();
  analogValue = analogRead(pin_Pot);
  Serial.println(analogValue);
  if(LED4status)
  {digitalWrite(pin_Led_4, HIGH);}
  else
  {digitalWrite(pin_Led_4, LOW);}
  
  if(LED3status)
  {digitalWrite(pin_Led_3, HIGH);}
  else
  {digitalWrite(pin_Led_3, LOW);}
}

void handle_OnConnect() {
  LED4status = LOW;
  LED3status = LOW;
  Serial.println("GPIO2 Status: OFF | GPIO27 Status: OFF");
  Serial.println("Potensio Read Ready");
  server.send(200, "text/html", SendHTML(LED4status,LED3status, analogValue)); 
}

void handle_LED4on() {
  LED4status = HIGH;
  Serial.println("GPIO4 Status: ON");
  server.send(200, "text/html", SendHTML(true,LED3status, analogValue)); 
}

void handle_LED4off() {
  LED4status = LOW;
  Serial.println("GPIO4 Status: OFF");
  server.send(200, "text/html", SendHTML(false,LED3status, analogValue)); 
}

void handle_LED3on() {
  LED3status = HIGH;
  Serial.println("GPIO5 Status: ON");
  server.send(200, "text/html", SendHTML(LED4status,true, analogValue)); 
}

void handle_LED3off() {
  LED3status = LOW;
  Serial.println("GPIO5 Status: OFF");
  server.send(200, "text/html", SendHTML(LED4status,false, analogValue)); 
}

void handle_NotFound(){
  server.send(404, "text/plain", "Not found");
}

String SendHTML(uint8_t LED4stat,uint8_t LED3stat, int analogVal){
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
      
        if(LED4stat){
            ptr +="<p>LED4 Status: ON</p><a class=\"button button-off\" href=\"LED4off\">OFF</a>\n";
        }
        else{
            ptr +="<p>LED4 Status: OFF<p><a class=\"button button-on\" href=\"LED4on\">ON</a>\n";
        }
        
        if(LED3stat){
            ptr +="<p>LED3 Status: ON</p><a class=\"button button-off\" href=\"LED3off\">OFF</a>\n";
        }
        else{
            ptr +="<p>LED3 Status: OFF<p><a class=\"button button-on\" href=\"LED3on\">ON</a>\n";
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