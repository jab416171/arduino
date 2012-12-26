int switchPin = 8;
int ledPin = 13;

void setup()
{
  pinMode(switchPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop()
{
	digitalWrite(ledPin, digitalRead(switchPin));
}
