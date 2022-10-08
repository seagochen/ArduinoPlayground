void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

    int x = 15;
  int n = 0;
  int res = bitClear(x, n);
  Serial.print(res, BIN); // print the output of bitClear(x,n)
  Serial.println("\n--------------");

  n = 1;
  res = bitClear(x, n);
  Serial.print(res, BIN); // print the output of bitClear(x,n)
  Serial.println("\n--------------");

  n = 2;
  res = bitClear(x, n);
  Serial.print(res, BIN); // print the output of bitClear(x,n)
  Serial.println("\n--------------");

  n = 3;
  res = bitClear(x, n);
  Serial.print(res, BIN); // print the output of bitClear(x,n)
  Serial.println("\n--------------");
}

void loop() {


}
