void setup()
{
  Serial.begin(9600);

  pinMode(8, OUTPUT);
}

void loop()
{
  if (Serial.available()) {
    char cmd = Serial.read();

    if (cmd == 'A') {
      digitalWrite(8, HIGH);
    }

    if (cmd == 'Q') {
      digitalWrite(8, LOW);
    }

    Serial.println(cmd);
  }
}
