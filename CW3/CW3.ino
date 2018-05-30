#define ECHOPIN 3
#define TRIGPIN 2

int sensorPin = A0;
unsigned int sensorValue = 0;

int led1 = 9;     
int buzzer = 8;
int led2 = 11;

char inVal;

void setup() {
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);

  pinMode(led1, OUTPUT); 
  pinMode(led2, OUTPUT);
  pinMode(buzzer, OUTPUT);
  
  pinMode(1,OUTPUT);
  pinMode(0,INPUT);
  
  Serial.begin(115200);
  Serial1.begin(115200);

}
  
void loop() {    
  
  digitalWrite(TRIGPIN,LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGPIN,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN,LOW);
  float distance = pulseIn(ECHOPIN,HIGH)/58.00;
  
  sensorValue = analogRead(sensorPin);
  
  while (Serial1.available()>0)
  {
    char inVal=char (Serial1.read());    
    
    if(inVal == 'a') 
    {                                   
      digitalWrite(led1, HIGH);        
      Serial1.println("Open LED1"); 
      delay(2000);        
      digitalWrite(led1, LOW);
    }
     else if(inVal == 'b')
    {
      Serial1.println("Open LED2");
      digitalWrite(led2,HIGH);
      delay(100);
      digitalWrite(led2,LOW);
      delay(100);
      digitalWrite(led2,HIGH);
      delay(100);
      digitalWrite(led2,LOW);
    }
    else if(inVal == 'c')
    {
      digitalWrite(buzzer,HIGH);
      Serial1.println("Open buzzer");
      tone(buzzer,500,800000);
    }   
    else if(inVal == 'd')
    {
      digitalWrite(buzzer,LOW);
      Serial1.println("Stop buzzer");
      noTone(buzzer);
    }
    
    else if(inVal == 'e')
    {
      Serial1.print("Distance is");
       Serial1.print(distance);
       Serial1.println("cm");
       delay(200);
    }     
   else if (inVal == 'f')
    {
      Serial1.print("Light is");
        Serial1.println(sensorValue);
    }
    
    
    else
    {
      Serial1.println("Waiting for command......");
      delay(1000);
    }
  }
  // put your main code here, to run repeatedly:
}
//
//void SRFValue()
//{
//  digitalWrite(TRIGPIN,LOW);
//  delayMicroseconds(2);
//  digitalWrite(TRIGPIN,HIGH);
//  delayMicroseconds(10);
//  digitalWrite(TRIGPIN,LOW);
//  float distance = pulseIn(ECHOPIN,HIGH)/58.00;
//           Serial1.print(distance);
//         Serial1.println("cm");
//         delay(200);
//}
//
//void LDRValue()
//{
//        Serial1.println(sensorValue);
//}

