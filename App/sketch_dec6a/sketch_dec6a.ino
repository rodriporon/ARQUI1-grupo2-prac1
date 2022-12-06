
char dataIn = "";

void setup() {
  Serial.begin(9600);

}

void loop() {
  if (Serial.available()) {
    dataIn = Serial.read();

    Serial.println("Recibiendo datos");
  }

}
