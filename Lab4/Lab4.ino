/*
                A
             ________
            |        |
         F  |        |  B
            |   G    |
            |________|
            |        |
            |        |  C
        E   |        |
            |________|            
                D

*/
// pin assignments
/* 
specify pins on the 7-seg display that for your Arduino
example you can connect the A segment of the display to the pin 2 on the Arduino.
*/

int pinDigit = 2;


//int A=2;
//int B=3;
//int C=4;
//int D=5;
//int E=6;
//int F=7;
//int G=8;

int COM1=10;
int COM2=11;
int COM3=12;
int COM4=13;



void setup() {
  // put your setup code here, to initialize all the pins 
  pinMode(COM1, OUTPUT);
  pinMode(COM2, OUTPUT);  
  pinMode(COM3, OUTPUT);  
  pinMode(COM4, OUTPUT);

  for(int x=0;x<8;x++)
  pinMode(pinDigit+x,OUTPUT);

}

void displayDigit(unsigned char digit)
{
  unsigned char table[][8]={
  {0,0,0,0,0,0,1,1},    //0
  {1,0,0,1,1,1,1,1},    //1
  {0,0,1,0,0,1,0,1},    //2
  {0,0,0,0,1,1,0,1},    //3
  {1,0,0,1,1,0,0,1},    //4
  {0,1,0,0,1,0,0,1},    //5
  {0,1,0,0,0,0,0,1},   //6
  {0,0,0,1,1,1,1,1},    //7
  {0,0,0,0,0,0,0,1},    //8
  {0,0,0,0,1,0,0,1},   //9
  };

  if (digit>=10) return;
  for(unsigned char x=0;x<8;x++)
  digitalWrite(pinDigit+x,table[digit][x]);
  
}
void loop() {
    digitalWrite(COM1,HIGH);
  digitalWrite(COM2,HIGH);
  digitalWrite(COM3,HIGH);
  digitalWrite(COM4,HIGH);
  
  for(int x=0;x<10;x++){
    displayDigit(x);
    delay(1000);
  }
  for(int y=10;y>0;y--){
    displayDigit(y);
    delay(1000);
  }
  
}

