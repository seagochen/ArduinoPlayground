#define LATCH_PIN 4 // ST_CP
#define CLOCK_PIN 8 // SH_CP
#define DATA_PIN  2 // DS

void clock_signal(void)
{
  digitalWrite(CLOCK_PIN, HIGH);
  delayMicroseconds(500);
  digitalWrite(CLOCK_PIN, LOW);
  delayMicroseconds(500);  
}

void latch_enable(void)
{
  digitalWrite(LATCH_PIN, HIGH);
  delayMicroseconds(500);
  digitalWrite(LATCH_PIN, LOW);  
}

void send_data(unsigned int data)
{
  int i;
  unsigned hold;

  for (i = 0; i < 8; i++) {
    if ((data >> i) & (0x01)) 
      digitalWrite(DATA_PIN, HIGH);
    else
      digitalWrite(DATA_PIN, LOW);

    clock_signal();
  }
  latch_enable();
}


void setup()
{
  pinMode(LATCH_PIN, OUTPUT);
  pinMode(DATA_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);

  digitalWrite(LATCH_PIN, LOW);
  digitalWrite(CLOCK_PIN, LOW);
  digitalWrite(DATA_PIN, LOW);
}

void loop()
{
  for (unsigned sig = 0b00000000; sig < 0b100000000; sig++) 
  {
    send_data(sig);
    delay(1000);
  }
}
