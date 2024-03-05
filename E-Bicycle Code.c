#include <SoftwareSerial.h>

SoftwareSerial bluetooth(10, 11);
int motorPin1 = 2; 
int motorPin2 = 3; 

void setup() {
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);

  Serial.begin(9600);
  bluetooth.begin(9600);
}

void loop() {
  if (bluetooth.available()) {
    char command = bluetooth.read();


    switch (command) {
      case 'L':
        lockBicycle();
        break;
      case 'U':
        unlockBicycle();
        break;
      default:
        break;
    }
  }
}

void lockBicycle() {
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  delay(2000); 
  digitalWrite(motorPin1, LOW);
}

void unlockBicycle() {
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  delay(2000); 
  digitalWrite(motorPin2, LOW);
}
