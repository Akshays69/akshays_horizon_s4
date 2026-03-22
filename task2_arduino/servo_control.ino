#include <Servo.h>

Servo myServo;
int potentiometer = A0;
int ledPin = 7;

void setup() {
  myServo.attach(9);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int value = analogRead(potentiometer);
  int angle = map(value, 0, 1023, 0, 180);

  if (angle > 68) {
    myServo.write(68);
    digitalWrite(ledPin, HIGH);
  } else {
    myServo.write(angle);
    digitalWrite(ledPin, LOW);
  }

  delay(10);
}
