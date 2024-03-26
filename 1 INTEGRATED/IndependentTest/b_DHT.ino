// Aliasing Library DHT -> dht
DHT dht(DHTPIN, DHTTYPE);

void init_dht(){
  dht.begin();
}

float read_Hdht(){
  // Return variable untuk menyimpan Nilai Pembacaan sensor rain secara Analog
  return dht.readHumidity();
}

float read_Tdht(){
  // Return variable untuk menyimpan Nilai Pembacaan sensor rain secara Analog
  return dht.readTemperature();
}

void read_dht_to_lcd(){
  unsigned long time_now=millis();
  if(time_now-time_last>=500){
    lcd_putsxy(8,0, "        ");
    lcd_putsxy(8,0, String(read_Hdht()) + "%");
    lcd_putsxy(6,1, "        ");
    lcd_putsxy(6,1, String(read_Tdht()) + "C");
    Serial.print(F("Kelembapan: "));
    Serial.print(dht.readHumidity());
    Serial.print(F("%  Suhu: "));
    Serial.print(dht.readTemperature());
    Serial.print(F("°C "));
    time_last=time_now;
  }
}