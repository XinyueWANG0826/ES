int sensorPin = A0;            
unsigned int sensorValue = 0;  
int LED=9;

void setup()
{

  Serial.begin(9600);    
  pinMode(LED, OUTPUT);
}

void loop()
{
  
  sensorValue = analogRead(sensorPin); 
  Serial.println(sensorValue);

  if (sensorValue<500)
  {
    for(int i;i<=5;i++)
    {
      digitalWrite(LED, HIGH);
      delay(200);
      digitalWrite(LED, LOW);
      delay(200);
    }
  }

}
