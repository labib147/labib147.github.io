/*
Author: Md Nefaur Rahman Labib
Created Date: 13 Nov 2019
Web: labib147.github.io
E-mail: nefaurrahmanlabib147@gmail.com
*/
//Connection with Arduino Uno

////////////////motor variables//////////

int motorLA = A2;
int motorLB = A3;
int motorL_PWM = 10;

int motorRA = A0;
int motorRB = A1;
int motorR_PWM = 11;

int speedL = 200;
int speedR = 200;

////////////////Sensor variables//////////

int sensorPin[] = {2, 3, 4, 5, 6, 7, 8, 9};  //pin numbers of the array
int sensorVal[8]; // variable to store sensor values
//////////////////////////////////////////


void setup() {

  ///motor pin setup
  pinMode(motorLA, OUTPUT);
  pinMode(motorLB, OUTPUT);
  pinMode(motorRA, OUTPUT);
  pinMode(motorRB, OUTPUT);

  //sensor setup
  for (int i = 0; i < 8; i++) {
    pinMode(sensorPin[i], INPUT);
  }
  Serial.begin(9600);

}

void loop() {
  IR_sensorReadUpdate();
  if ( sensorVal[7] == 0 && sensorVal[6] == 0 && sensorVal[5] == 0 && sensorVal[4] == 1 && sensorVal[3] == 1 && sensorVal[2] == 0 && sensorVal[1] == 0 && sensorVal[0] == 0 ) {
    speedL = 255;
    speedR = 255;
    Forward();
  }
  else if ( sensorVal[7] == 0 && sensorVal[6] == 0 && sensorVal[5] == 1 && sensorVal[4] == 1 && sensorVal[3] == 0 && sensorVal[2] == 0 && sensorVal[1] == 0 && sensorVal[0] == 0) {
    speedL = 200;
    speedR = 255;
    Forward();
  }
  else if ( sensorVal[7] == 0 && sensorVal[6] == 0 && sensorVal[5] == 0 && sensorVal[4] == 0 && sensorVal[3] == 1 && sensorVal[2] == 1 && sensorVal[1] == 0 && sensorVal[0] == 0) {
    speedL = 255;
    speedR = 200;
    Forward();
  }

}

///////////////////methods//////////////

void IR_sensorReadUpdate() {
  for (int i = 0; i < 8; i++) {
    sensorVal[i] = digitalRead( sensorPin[i] );
    Serial.print( sensorVal[i] );
    Serial.print(" ");
  }
  Serial.println();
}

////////////motor methods/////////////

void Forward() {
  analogWrite(motorL_PWM, speedL);
  digitalWrite(motorLA, HIGH);
  digitalWrite(motorLB, LOW);

  analogWrite(motorR_PWM, speedR);
  digitalWrite(motorRA, HIGH);
  digitalWrite(motorRB, LOW);
}

//happy coding :D
