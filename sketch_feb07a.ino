#include <Servo.h>
Servo servo;

bool pressedBtn = false;
int delayTime = 0;

void setup() {
  pinMode(A1, INPUT);
  pinMode(A0, INPUT);
  pinMode(13, OUTPUT);
  pinMode(5, OUTPUT);
  servo.attach(5);
  digitalWrite(13, HIGH);
  Serial.begin(9600);
}

void loop() {

  Swap();

  if (pressedBtn) {

    digitalWrite(13, LOW);

    for (int i = 0; i < 180; i++) {
      Swap();
      if (pressedBtn) {
        delayTime = analogRead(A0);
        servo.write(i);
        delay(delayTime);
      }
      else {
        //break;
      }
    }
  }

  if (pressedBtn) {
    for (int i = 180; i > 0; i--) {
      Swap();
      if (pressedBtn) {
        delayTime = analogRead(A0);
        servo.write(i);
        delay(delayTime);
      }
      else {
        //break;
      }
    }

    //  Serial.write(analogRead(A0));
    //  servo.write(180);
    //  delay(500);
    //  servo.write(0);
    //  delay(500);
  }
}
void Swap() {
  if (!digitalRead(A1)) {
    pressedBtn = !pressedBtn;
    Serial.write(pressedBtn);
  }
}
