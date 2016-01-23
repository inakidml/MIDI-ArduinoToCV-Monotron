#include <SoftwareSerial.h>

#include <SPI.h>

#include <MCPDAC.h>


SoftwareSerial portOne(8, 9);
byte commandByte;
byte noteByte;
byte velocityByte;
//int pitchPin=DAC0;

int gatePin=5;
int x;
int nota;
int volts=0;


void setup(){
 Serial.begin(9600);
 pinMode(13,OUTPUT);
  digitalWrite(13,HIGH);
  portOne.begin(31250);

 
  delay(200);
//  Serial.println("serial arrancado");
//  pinMode(pitchPin, OUTPUT);
  pinMode(gatePin, OUTPUT);
 // analogWriteResolution(12);
 // CS on pin 10, no LDAC pin (tie it to ground).
  
  
  //MCPDAC.begin(10);
  
  // Set the gain to "HIGH" mode - 0 to 4096mV.
  MCPDAC.setGain(CHANNEL_A,GAIN_HIGH);
  
  // Do not shut down channel A, but shut down channel B.
  MCPDAC.shutdown(CHANNEL_A,false);
  MCPDAC.shutdown(CHANNEL_B,true);
 
}

void checkMIDI(){
 /* do{
    if (portOne.available()){
      commandByte = portOne.read();//read first byte
      noteByte = portOne.read();//read next byte
      velocityByte = portOne.read();//read final byte
      Serial.print((commandByte),HEX);
      Serial.print(" ");
      Serial.print((noteByte),HEX );
      Serial.print(" ");
      Serial.println((velocityByte), HEX);
    }
  }
  while (portOne.available() > 2);//when at least three bytes available
  */
   while(portOne.available()){
    if (portOne.available()){
      commandByte = portOne.read();//read first byte
      
      Serial.println((commandByte),HEX);
     delay(5) ;
      
    }
  }

}

/*void MIDImessage(int MIDIcommand, int MIDInote, int MIDIvelocity) {
  portOne.write(MIDIcommand);//send note on or note off command 
  portOne.write(MIDInote);//send pitch data
  portOne.write(MIDIvelocity);//send velocity data
}
*/
void loop(){
 
  
  //Serial.println(map(analogRead(A0),0,1024,0,5000));

  
  checkMIDI();
  //MIDImessage(commandByte, noteByte, velocityByte);
  //portOne.write(commandByte);
  if (commandByte==144){
    
      digitalWrite(gatePin, HIGH);
      digitalWrite(13,HIGH);
     //MCPDAC.setVoltage(CHANNEL_A,map(noteByte,36,84,0,4096));
      //delay(10);
  }
  else {
      if (commandByte==144&&velocityByte==0 || commandByte==128){
        digitalWrite(gatePin, LOW);
        digitalWrite(13,LOW);
      }
  }
  //delay(200);
  digitalWrite(gatePin,LOW);
  digitalWrite(13,LOW);
  
/*  digitalWrite(gatePin, HIGH);
  MCPDAC.setVoltage(CHANNEL_A,volts&0x0fff);
  Serial.println(map(analogRead(A0),0,1024,0,5000));
  //Serial.print("volts= ");
  Serial.println(volts&0x0fff);
  //volts+=100;
  //i++;
  
  delay(2000);
   volts=volts+1024/12;
*/   
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
