//=====================
//HTML code for webpage
//=====================
String webpageCont = 
R"=====(
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
        #RectangleBgPot
        {
            width:50vw;
            height:12px;
            background-color: rgb(153, 153, 153);
            margin: 0px auto 35px;
        }
        #RectanglePot
        {
            /* width:500px; */
            height:12px;
            background-color: #0969ad;
            margin: 0px;
        }

        .captPot{
          font-size: 20px;
          margin: 10px 0px;
        }

        .KetPot{
          width:50vw;
          display: flex;
          margin: 40px auto 0px;
          justify-content: space-between;
        }

        @media(max-width: 1000px){
          h1 {margin: 180px auto 50px;}
        }
        
    </style>
  </head>

  <body>
    <h1>ESP32 WEB SERVER</h1>
    <h3>Sebagai AP (AcessPoint) Mode</h3>
    <!-- <p>LED1 Status: ON</p><a class="button button-off" href="led1off">OFF</a> -->
    <p>LED1 Status: OFF<p><a class="button button-on" href="led1on">ON</a>
    
    <p>LED2 Status: ON</p><a class="button button-off" href="led2off">OFF</a>
    <!-- <p>LED2 Status: OFF<p><a class="button button-on" href="led2on">ON</a> -->

    <p>Nilai Potensiometer</p>
    <h1 id="val_pot">3000</h1>
    <div class="KetPot">
      <div class="captPot">0V</div>
      <div class="captPot">3,3V</div>
    </div>
    <div id="RectangleBgPot">
      <div id="RectanglePot"></div>
    </div>
        
    <h3>by TrainWare</h3>
  </body>

  <script>
  InitWebSocket()
  function InitWebSocket()
  {
    var width = document.getElementById('RectangleBgPot').offsetWidth;
    websock = new WebSocket('ws://'+window.location.hostname+':81/');
    websock.onmessage=function(evt)
    {
       JSONobj = JSON.parse(evt.data);
       document.getElementById('val_pot').innerHTML = JSONobj.POT;
       var pot = parseInt(JSONobj.POT)/4095 * width;
       document.getElementById("RectanglePot").style.width = pot+"px";
    }
  }
  </script>
  </html>
)=====";
