int load = 7;
int clockEnablePin = 4;
int dataIn = 5;
int clockIn = 6;
/*int load1 = 17;
int clockEnablePin1 = 14;
int dataIn1 = 15;
int clockIn1 = 16;
const int latchPin1 = 1;
const int clockPin1 = 2;
const int dataPin1 = 3;*/
const int latchPin = 10;
const int clockPin = 11;
const int dataPin = 12;

void setup()
{ 
  // Setup Serial Monitor
  Serial.begin(9600);
  
  //74HC165 pins
  pinMode(load, OUTPUT);
  pinMode(clockEnablePin, OUTPUT);
  pinMode(clockIn, OUTPUT);
  pinMode(dataIn, INPUT);
 /*  pinMode(load1, OUTPUT);
  pinMode(clockEnablePin1, OUTPUT);
  pinMode(clockIn1, OUTPUT);
  pinMode(dataIn1, INPUT);*/
  
  //74HC595 pins
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
   /*pinMode(latchPin1, OUTPUT);
  pinMode(clockPin1, OUTPUT);
  pinMode(dataPin1, OUTPUT);*/
  
}

 void loop() {
  // Read Switches

  // Write pulse to load pin
 {
  
  digitalWrite(load, LOW);
  delayMicroseconds(5);
  digitalWrite(load, HIGH);
  delayMicroseconds(5);
  
  /*digitalWrite(load1, LOW);
  delayMicroseconds(5);
  digitalWrite(load1, HIGH);
  delayMicroseconds(5);*/
  
// Get data from 74HC165
  digitalWrite(clockIn, HIGH);
  digitalWrite(clockEnablePin, LOW);
  byte incoming = shiftIn(dataIn, clockIn, LSBFIRST);
  digitalWrite(clockEnablePin,HIGH);
   /*digitalWrite(clockIn1, HIGH);
  digitalWrite(clockEnablePin1, LOW);
  byte incoming1 = shiftIn(dataIn, clockIn1, LSBFIRST);
  digitalWrite(clockEnablePin1,HIGH);*/
  
//Print to serial monitor
  Serial.print("Pin States:\r");
  Serial.println(incoming, BIN);
  /*Serial.print("Pin States:\r");
  Serial.println(incoming1, BIN);*/
  
  // Write to LEDs
  
  // ST_CP LOW to keep LEDs from changing while reading serial data 
  digitalWrite(latchPin, LOW);
 // digitalWrite(latchPin1, LOW);
  
  // Shift out the bits
  shiftOut(dataPin, clockPin, MSBFIRST, ~incoming);
  //shiftOut(dataPin1, clockPin1, LSBFIRST, incoming1);
  
  // ST_CP HIGH change LEDs
  digitalWrite(latchPin, HIGH);
  // digitalWrite(latchPin1, HIGH);
  
  delay(500);
 }
 }
