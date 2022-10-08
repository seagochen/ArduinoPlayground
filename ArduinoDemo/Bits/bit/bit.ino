void setup()
{
  pinMode(13, OUTPUT);
}

void loop()
{
    int bits = bit(0);
    for (int i = 0; i  < bits; i++) {
        digitalWrite(13, HIGH);
        delay(100);

        digitalWrite(13, LOW);
        delay(100);
    }

    delay(1000);
}
