void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  int x = 13;
  int n = 0;
 
   bitSet(x, 1);
   Serial.print(x, BIN);
}

void loop() {
}
