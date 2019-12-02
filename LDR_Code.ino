//author Labib
//contact@ nefaurrahmanlabib147@gmail.com

int v=0;
void setup()

{
pinMode(A0, INPUT);
pinMode(8, OUTPUT);
digitalWrite(8,HIGH);
Serial.begin(9600);
}

void loop()

{
v =analogRead(A0);
if(v<700){
  digitalWrite(8,HIGH);
  Serial.println(v);
}else if(v>750){
  digitalWrite(8,LOW);
  Serial.println(v);
  }
}
