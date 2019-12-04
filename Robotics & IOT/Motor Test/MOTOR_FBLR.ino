  /*
  Author: Md Nefaur Rahman Labib
  Date: 13 Nov 2019
  Web: labib147.github.io
  E-mail: nefaurrahmanlabib147@gmail.com
  Connection Diagram:
  Arduino <-->  Motor Driver
    D2    <--> MotorA1
    D4    <--> MotorA2
    D3    <--> MotorA-PWM
    D5    <--> MotorB1
    D7    <--> MotorB2
    D6    <--> MotorB-PWM

  Description:
  This code will help you to test any L293D or L298N based standard Motor Driver.This default code will drive your every possible combination. Use this functions and do further modification to make it work in your real project.
  */
  //The code is written for Arduino Mega

  byte LeftMotorA = 26;
  byte LeftMotorB = 28;
  byte LeftMSpeed = 10; 

  byte RightMotorA = 22;
  byte RightMotorB = 24;
  byte RightMSpeed = 11;

  void setup() 
  {
  Serial.begin(9600);
  //Initialized Motor Driver Pins as Output
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  }

  void loop() 
  {
  MotorSpeed(); // Set Motor Speed
  Serial.println("Driving Forward");
  drive_forward();
  delay(1000);//1 second Delay
  motor_stop();

  Serial.println("Driving Forward");
  drive_backward();
  delay(1000);
  motor_stop();

  Serial.println("Turnning Left");
  turn_left();
  delay(1000);
  motor_stop();

  Serial.println("Turnning Left");
  turn_right();
  delay(1000);
  motor_stop();

  Serial.println("Testing Done !");
  delay(2000);
  }

  // Motor Driving Functions

  // Set Motor Speed 0 for stop & 255 is max speed of motor divided in voltage from range (0-255)
  void MotorSpeed(){
  analogWrite(LeftMSpeed, 255);
  analogWrite(RightMSpeed,255);
  }
  //Stop Both Motor
  void motor_stop(){
  digitalWrite(LeftMotorA, LOW); 
  digitalWrite(LeftMotorB, LOW); 
  digitalWrite(RightMotorA, LOW); 
  digitalWrite(RightMotorB, LOW);
  delay(5);
  }

  void drive_forward(){
  digitalWrite(LeftMotorA, HIGH); 
  digitalWrite(LeftMotorB, LOW); 
  digitalWrite(RightMotorA, HIGH); 
  digitalWrite(RightMotorB, LOW);
  delay(5);
  }

  void drive_backward(){
  digitalWrite(LeftMotorA, LOW); 
  digitalWrite(LeftMotorB, HIGH); 
  digitalWrite(RightMotorA, LOW); 
  digitalWrite(RightMotorB, HIGH);
  delay(5); 
  }

  void turn_left(){
  digitalWrite(LeftMotorA, LOW); 
  digitalWrite(LeftMotorB, LOW); 
  digitalWrite(RightMotorA, HIGH); 
  digitalWrite(RightMotorB, LOW);
  delay(5); 
  }

  void turn_right(){
  digitalWrite(LeftMotorA, HIGH); 
  digitalWrite(LeftMotorB, LOW); 
  digitalWrite(RightMotorA, LOW); 
  digitalWrite(RightMotorB, LOW);
  delay(5); 
  }

//happy coding :D
