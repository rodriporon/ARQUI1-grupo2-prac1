
String serialText = "";

void setup() {
  Serial.begin(9600);

}

void loop() {
  while(Serial.available()){
    delay(10);
    char c = Serial.read();
      serialText += c;
    
  }

  Serial.println(serialText);  


}
