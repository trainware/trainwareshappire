/*=================================================== SOIL SENSE ===========*/
void init_soil(){
  pinMode(pin_D0Soil, INPUT);
}

int read_D0soil(){
  return digitalRead(pin_D0Soil);
}

//dia akan bernilai maksimal atau 4095 jika probe tidak terpasang 
int read_A0soil(){
  return analogRead(pin_A0Soil);
}
/*=================================================== POTENSIOMETER ===========*/
float read_pot(){
  return analogRead(pin_Pot);
}

float read_potpercent(){
  return floatMap(analogRead(pin_Pot), 0, 4095, 0, 3.3);
}

/*=================================================== FLAME ===========*/
void init_flame(){
  // meng Set pin flame sensor pada ESP32 sebagai INPUT
  pinMode(pin_Flame, INPUT);
}

int read_flame(){
  // Return variable pembacaan FlameSensor
  return digitalRead(pin_Flame);
}