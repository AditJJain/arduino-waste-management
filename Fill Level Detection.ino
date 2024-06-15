int trigger = 5;
int echo = 6;

float timeInMicro = 0.0;
int distance = 0;

int redLed = 11;
int blueLed = 13;
int greenLed = 12;

void setup() {
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  digitalWrite(trigger, LOW);
  Serial.begin(9600);
  pinMode(redLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
}

void loop() {
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);

  timeInMicro = pulseIn(echo, HIGH);
  distance = timeInMicro / 29 / 2;

  Serial.println(distance);

  if (distance < 5) {
    digitalWrite(redLed, HIGH);
    digitalWrite(blueLed, LOW);
    digitalWrite(greenLed, LOW);
  } else if (distance >= 5 && distance < 12.5) {
    digitalWrite(redLed, LOW);
    digitalWrite(blueLed, HIGH);
    digitalWrite(greenLed, LOW);
  } else if (distance >= 12.5) {
    digitalWrite(redLed, LOW);
    digitalWrite(blueLed, LOW);
    digitalWrite(greenLed, HIGH);
  }

  delay(1000);
}
