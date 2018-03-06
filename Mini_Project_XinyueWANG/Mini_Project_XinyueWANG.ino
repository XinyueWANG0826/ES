#define ECHOPIN 3
#define TRIGPIN 2

int rled = 4;
int yled = 5;
int gled = 6;

int buzzer = 7;
int LDR = A0;
unsigned int sensorValue = 0;

char inVal = '1';

void setup() {
  Serial.begin(9600);
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
  pinMode(rled, OUTPUT);
  pinMode(yled, OUTPUT);
  pinMode(gled, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(LDR, OUTPUT);
 }

void loop() {
  
  while (Serial.available()>0)
    inVal=Serial.read();

  if(inVal == '1')
    {   
       digitalWrite(buzzer,LOW);
       noTone(buzzer); 
        
       digitalWrite(rled,HIGH);
       delay(2000);
       digitalWrite(rled,LOW);

       digitalWrite(yled,HIGH);
       delay(1000);
       digitalWrite(yled,LOW);

       digitalWrite(gled,HIGH);
       delay(2000);
       digitalWrite(gled,LOW);

       digitalWrite(yled,HIGH);
       delay(1000);
       digitalWrite(yled,LOW);
       }
     
    else if (inVal == '2')
    {

       digitalWrite(TRIGPIN, LOW);
       delayMicroseconds(2);
       digitalWrite(TRIGPIN, HIGH);
       delayMicroseconds(10);
       digitalWrite(TRIGPIN, LOW);
       float distance = pulseIn(ECHOPIN, HIGH)/58.00;
       Serial.print("Distance:");
       Serial.print(distance);
       Serial.println("cm");
       delay(200);
       if(distance<10)
       {
        digitalWrite(buzzer, HIGH);
        tone(buzzer,500);
        for (int i=0; i<10; i++)
        {
          digitalWrite(yled,HIGH);
          delay(100);
          digitalWrite(yled,LOW);
          delay(100);
         
       
        }
       }
       if(distance>=10)
       {
        digitalWrite(buzzer,LOW);
        noTone(buzzer);
        digitalWrite(rled,HIGH);
       delay(2000);
       digitalWrite(rled,LOW);

       digitalWrite(yled,HIGH);
       delay(1000);
       digitalWrite(yled,LOW);

       digitalWrite(gled,HIGH);
       delay(2000);
       digitalWrite(gled,LOW);

       digitalWrite(yled,HIGH);
       delay(1000);
       digitalWrite(yled,LOW);
       } 
      }
     
    else if(inVal == '3')
    {

        sensorValue = analogRead(LDR);
        Serial.print("LightValue:");
        Serial.println(sensorValue);

        digitalWrite(TRIGPIN, LOW);
        delayMicroseconds(2);
        digitalWrite(TRIGPIN, HIGH);
        delayMicroseconds(10);
        digitalWrite(TRIGPIN, LOW);
        float distance = pulseIn(ECHOPIN, HIGH)/58.00;
        Serial.print("Distance:");
        Serial.print(distance);
        Serial.println("cm");
        delay(200);
        
        if(sensorValue<7)
        {
          digitalWrite(rled,HIGH);          
        }
        else
        {
          digitalWrite(rled,LOW);
        }
        if(distance<10)
        {
          digitalWrite(gled, HIGH);
          digitalWrite(rled, LOW);
        }
        else
        {
          digitalWrite(gled, LOW);
        }
      }
    
  }




  
