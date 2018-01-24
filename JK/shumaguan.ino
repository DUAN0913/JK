#include<CurieTime.h>
/*段选*/
int latchPin = 13;//STCP
int clockPin = 12;//SHCP
int dataPin = 11;//DATA
/*位选*/
int latchPinW = 10;
int clockPinW = 9;
int dataPinW = 8;

int indexMO = 0;
int indexMT = 0;
int indexHO = 0;
int indexHT = 0;
int i = 0;

const byte LED[10] = {0x3f,0x06,0x5b,0x4f,0x6d,0x7d,0x07,0x7f,0x6f};
const byte WEI[4] = {0x01,0x02,0x04,0x08};

int nowMinute;//分
int nowHour;//时

int DXX;
int ZW;

void setup(){
  pinMode(latchPin,OUTPUT);
  pinMode(clockPin,OUTPUT);
  pinMode(dataPin,OUTPUT);
  }

void loop(){
  setTime(0,00,00,00,0,0);
  nowMinute = minute();
  nowHour = hour();
  indexMO = nowMinute%10;
  indexMT = nowMinute/10;
  indexHO = nowHour%10;
  indexHT = nowHour/10;
  xianshi();
  }

void xianshi(){
  digitalWrite(latchPinW,LOW);
  shiftOut(dataPinW,clockPinW,LSBFIRST,WEI[0]);
  digitalWrite(latchPinW,HIGH);
  delay(1);
  digitalWrite(latchPin,LOW);
  shiftOut(dataPin,clockPin,MSBFIRST,LED[indexMO]);
  digitalWrite(latchPin,LOW);
  delay(1);

  digitalWrite(latchPinW,LOW);
  shiftOut(dataPinW,clockPinW,LSBFIRST,WEI[1]);
  digitalWrite(latchPinW,HIGH);
  delay(1);
  digitalWrite(latchPin,LOW);
  shiftOut(dataPin,clockPin,MSBFIRST,LED[indexMT]);
  digitalWrite(latchPin,LOW);
  delay(1);

  digitalWrite(latchPinW,LOW);
  shiftOut(dataPinW,clockPinW,LSBFIRST,WEI[2]);
  digitalWrite(latchPinW,HIGH);
  delay(1);
  digitalWrite(latchPin,LOW);
  shiftOut(dataPin,clockPin,MSBFIRST,LED[indexHO]);
  digitalWrite(latchPin,LOW);
  delay(1);

  digitalWrite(latchPinW,LOW);
  shiftOut(dataPinW,clockPinW,LSBFIRST,WEI[3]);
  digitalWrite(latchPinW,HIGH);
  delay(1);
  digitalWrite(latchPin,LOW);
  shiftOut(dataPin,clockPin,MSBFIRST,LED[indexHT]);
  digitalWrite(latchPin,LOW);
  delay(1);
  }
