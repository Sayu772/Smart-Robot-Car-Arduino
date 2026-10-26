#include <Ultrasonic.h>
#include <Servo.h>

Ultrasonic u(8, 9);
Servo s;

// MOTOR PINS
int ENA = 11;
int IN1 = 12;
int IN2 = 13;
int IN3 = 7;
int IN4 = 6;
int ENB = 5;

char signal;
char mode = '6';
char incomingSignal;

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);


  analogWrite(ENA, 200);
  analogWrite(ENB, 200);

  Serial.begin(9600);

  s.attach(10);
  s.write(90);
  delay(500);
}

void loop() {

  if (Serial.available() > 0) {
    incomingSignal = Serial.read();


    if (incomingSignal == '5' || incomingSignal == '6') {
      mode = incomingSignal;
      Stop();
      if (mode == '5')
        s.write(90);
    }
    if (mode == '6') {
      signal = incomingSignal;
    }

    //Manual Mode
    if (mode == '6') {
      if (signal == '1') moveForward();
      else if (signal == '2') moveBackward();
      else if (signal == '3') turnLeft();
      else if (signal == '4') turnRight();
      else if (signal == '0') Stop();
    }
  }

  //Obstacle Avoiding Mode
  if (mode == '5') {
    int distance = u.read();

    if (distance > 20) {
      moveForward();
    } else {
      Stop();
      delay(300);

      s.write(35);
      delay(500);
      int rightDistance = u.read();

      s.write(145);
      delay(500);
      int leftDistance = u.read();

      s.write(90);
      delay(300);

      if (rightDistance > leftDistance) {
        turnRight();
        delay(500);
      } else {
        turnLeft();
        delay(500);
      }
      Stop();
      delay(200);
    }
  }
}


void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void moveBackward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void turnLeft() {
  s.write(125);
  delay(500);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnRight() {
  s.write(35);
  delay(500);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void Stop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
