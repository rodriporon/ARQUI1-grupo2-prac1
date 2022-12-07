#define LED 13

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
}

void loop() {
  if (Serial.available()) {
    
    // data será la cadena que se recibirá desde Java
    String data = Serial.readStringUntil('\n');


    if (data == "encender") {
      digitalWrite(LED, HIGH);
    }

    if (data == "apagar") {
      digitalWrite(LED, LOW);
    }

  }

}
