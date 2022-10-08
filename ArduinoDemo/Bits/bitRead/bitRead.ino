void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  int x = 13;
  int n = 0;
 
  for (int i = 0; i < 4; i++) {
    Serial.print(i);
    Serial.print(" --> ");

    int res = bitRead(x, i);
    Serial.print(res); // print the output of bitClear(x,n)
    Serial.println("\n--------------");
  }
}

void loop() {
}
