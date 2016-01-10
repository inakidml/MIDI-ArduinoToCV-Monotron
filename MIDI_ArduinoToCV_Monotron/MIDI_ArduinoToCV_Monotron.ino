#include <SPI.h>

#include <MCPDAC.h>



float a4=440;
float Bb4=466.16;
float B4 = 493.88;
float C5 = 523.25;
float Cs5 = 554.37;
float D5 = 587.33;
float Eb5 = 622.23;
float E5 = 659.26;
float F5 = 698.46;
float Fs5 = 739.99;
float G5 = 783.99;
float Ab5 = 830.61;
float a5 = 880.00;
 int i=0;

//int pitchPin=DAC0;
int gatePin=5;
int x;
int nota;
int volts =0;


void setup(){
  Serial.begin(9600);
  delay(200);
  Serial.println("serial arrancado");
//  pinMode(pitchPin, OUTPUT);
  pinMode(gatePin, OUTPUT);
 // analogWriteResolution(12);
 // CS on pin 10, no LDAC pin (tie it to ground).
  MCPDAC.begin(10);
  
  // Set the gain to "HIGH" mode - 0 to 4096mV.
  MCPDAC.setGain(CHANNEL_A,GAIN_HIGH);
  
  // Do not shut down channel A, but shut down channel B.
  MCPDAC.shutdown(CHANNEL_A,false);
  MCPDAC.shutdown(CHANNEL_B,true);
 
}

void loop(){
 
  
  //Serial.println(map(analogRead(A0),0,1024,0,5000));
  //delay(100 );
 // volts=2048;
  digitalWrite(gatePin, HIGH);
  MCPDAC.setVoltage(CHANNEL_A,volts&0x0fff);
  Serial.println(map(analogRead(A0),0,1024,0,5000));
  //Serial.print("volts= ");
  //Serial.println(volts);
  //volts+=100;
  //i++;
  
  delay(2000);
   volts=volts+1024/12;
//  digitalWrite(gatePin, HIGH);
//  MCPDAC.setVoltage(CHANNEL_A,volts&0x0fff);
  //Serial.println(map(analogRead(A0),0,1024,0,5000));
 // digitalWrite(gatePin, LOW);
// delay(2000);

  
/*
  //for(nota=1;nota<14;nota++){
    digitalWrite(gatePin, HIGH);
    Serial.println(nota);
    Serial.println(map(nota,1,13,1241,2850));
    digitalWrite(gatePin, HIGH);    
    analogWrite(DAC0, 1000);
    delay(500);
    digitalWrite(gatePin, LOW);
    delay(250);
    digitalWrite(gatePin, HIGH);
    analogWrite(DAC0,1000 );
    delay(500);
    digitalWrite(gatePin, LOW);
    delay(250);
    digitalWrite(gatePin, HIGH);
    analogWrite(DAC0,1000 );
    delay(1250);
    digitalWrite(gatePin, LOW);
    delay(250);
    digitalWrite(gatePin, HIGH);
    analogWrite(DAC0, 1000);
    delay(500);
    digitalWrite(gatePin, LOW);
    delay(250);
    digitalWrite(gatePin, HIGH);
    analogWrite(DAC0,1000 );
    delay(500);
    digitalWrite(gatePin, LOW);
    delay(250);
    digitalWrite(gatePin, HIGH);
    analogWrite(DAC0,1000 );
    delay(1250);
    digitalWrite(gatePin, LOW);
    delay(250);
    digitalWrite(gatePin, HIGH);
    analogWrite(DAC0, 1000);
    delay(500);
    digitalWrite(gatePin, LOW);
    delay(250);
    digitalWrite(gatePin, HIGH);
    analogWrite(DAC0,1000+((1850/12)*3) );
    delay(500);
    digitalWrite(gatePin, LOW);
    delay(250);
    digitalWrite(gatePin, HIGH);
    analogWrite(DAC0,1000-((1850/12)*4) );
    delay(500);
    digitalWrite(gatePin, LOW);
    delay(250);
    digitalWrite(gatePin, HIGH);
    analogWrite(DAC0,1000-((1850/12)*2) );
    delay(500);
    digitalWrite(gatePin, LOW);
    delay(250);
    digitalWrite(gatePin, HIGH);
    analogWrite(DAC0,1000);
    delay(2750);
    digitalWrite(gatePin, LOW);
    delay(250);

    digitalWrite(gatePin,LOW);
    //delay(2000);
    
  //}
  */
}
