int Led = 4 ;// define LED Interface
int buttonpin = 2; // define D0 Sensor Interface
int val = 0;// define numeric variables val
int sensorPin = A0;
 
void setup ()
{
  pinMode (Led, OUTPUT) ;// define LED as output interface
  pinMode (buttonpin, INPUT) ;// output interface D0 is defined sensor
  Serial.begin(9600);
}
 
void loop ()
{
  int sensorValue = analogRead(sensorPin)-521;
  delay(10);
  Serial.println(abs(sensorValue),DEC);
  val = digitalRead(buttonpin);// digital interface will be assigned a value of pin 3 to read val
  //if (sensorValue < 15)
  //{
    //digitalWrite (Led,LOW);
  //}
  //else
  //{
    //digitalWrite (Led, HIGH);
  //}
  
  if (val == HIGH) // When the sound detection module detects a signal, LED flashes
  {
    digitalWrite (Led, HIGH);
    delay(10);
  }
  else
  {
    digitalWrite (Led, LOW);
  }

}
