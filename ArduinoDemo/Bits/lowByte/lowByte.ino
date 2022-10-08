void setup() {
  Serial.begin(9600);
  while (!Serial) {}  // wait for serial port to connect. Needed for native USB port only

  int x = 0b1110110011110000;  // the 0b prefix indicates a binary constant
  Serial.println(x, BIN);

  // high byte (from left)
  byte res = highByte(x);
  Serial.println(res, BIN);

  // low byte (from right)
  res = lowByte(x);
  Serial.println(res, BIN);
}

void loop() {}
