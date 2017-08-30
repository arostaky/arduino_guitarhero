//Juan Patricio Di Bacco
/*
 Pin layouts are hardcoded in GPSX.c.
 For function details, refer to documents attached to this library.
 */
//import PSX lib:

#include <GPSXClass.h>
//const values:

const int BtnGreen = 8;
const int BtnRed = 9;
const int BtnYellow = 10;
const int BtnBlue = 11;
const int BtnOrange = 12;
int BtnGreenState = 0;
int lastButtonStateG = 0;
int BtnRedState = 0;
int lastButtonStateR = 0;
int BtnYellowState = 0;
int lastButtonStateY = 0;
int BtnBlueState = 0;
int lastButtonStateB = 0;
int BtnOrangeState = 0;
int lastButtonStateO = 0;

void setup()
{
  Serial.begin(9600);
  PSX.mode(PSX_PAD1, MODE_ANALOG, MODE_LOCK);

  PSX.motorEnable(PSX_PAD1, MOTOR1_ENABLE, MOTOR2_ENABLE);

  // Poll current state once.
  PSX.updateState(PSX_PAD1);
  //pin mode for btns:
  pinMode(BtnGreen, INPUT);
  pinMode(BtnRed, INPUT);
  pinMode(BtnYellow, INPUT);
  pinMode(BtnBlue, INPUT);
  pinMode(BtnOrange, INPUT);
}

void loop()
{
  PSX.updateState(PSX_PAD1);
  PSX.mode(PSX_PAD1, MODE_ANALOG, MODE_UNLOCK);
  if (PRESSED_CIRCLE(PSX_PAD1)) {
    Serial.println("Pressed circle");
    Serial.write(201);
    //PSX.motor(PSX_PAD1, MOTOR1_ON, 0x00);
  }

  if (RELEASED_CIRCLE(PSX_PAD1)) {
    Serial.println("Released circle");
    Serial.write(200);
    //PSX.motor(PSX_PAD1, MOTOR1_OFF, 0x00);
  }

  if (PRESSED_SQUARE(PSX_PAD1)) {
    Serial.println("Pressed square");
    Serial.write(211);
    //PSX.mode(PSX_PAD1, MODE_DIGITAL, MODE_UNLOCK);
  }

  if (RELEASED_SQUARE(PSX_PAD1)) {
    Serial.println("Released square");
    Serial.write(210);
  }

  if (PRESSED_CROSS(PSX_PAD1)) {
    Serial.println("Pressed cross");
    Serial.write(221);
    //PSX.mode(PSX_PAD1, MODE_ANALOG, MODE_UNLOCK);
    //PSX.motorEnable(PSX_PAD1, MOTOR1_ENABLE, MOTOR2_ENABLE);
  }

  if (RELEASED_CROSS(PSX_PAD1)) {
    Serial.println("Released cross");
    Serial.write(220);
  }
  if (PRESSED_TRIANGLE(PSX_PAD1)) {
    Serial.println("Pressed triangle");
    Serial.write(223);
  }

  if (RELEASED_TRIANGLE(PSX_PAD1)) {
    Serial.println("Released triangle");
    Serial.write(222);
    //PSX.motor(PSX_PAD1, MOTOR1_OFF, 0x00);
  }
  if (IS_DOWN_UP(PSX_PAD1)){
    Serial.println("Digital UP pressed");
    Serial.write(224);
  }
  if(RELEASED_UP(PSX_PAD1)){
    Serial.println("Digital UP released");
    Serial.write(223);
  }
  if (IS_DOWN_DOWN(PSX_PAD1)){
    Serial.println("Digital DOWN pressed");
    Serial.write(226);
  }
  if(RELEASED_DOWN(PSX_PAD1)){
    Serial.println("Digital DOWN released");
    Serial.write(225);

  }
  if(PRESSED_L2(PSX_PAD1)){
    Serial.println("Pressed L2");
    Serial.write(228);
  }
  if(RELEASED_L2(PSX_PAD1)){
    Serial.println("Released L2");
    Serial.write(227);
  }
  if(ANALOG_LEFT_Y(PSX_PAD1)<116){
    Serial.println("Analog Left Value Y:");
    Serial.println(ANALOG_LEFT_Y(PSX_PAD1));
    Serial.write(ANALOG_LEFT_Y(PSX_PAD1));
  }
  if(PRESSED_START(PSX_PAD1)){
    Serial.println("Pressed START");
    Serial.write(229);
  }
  if(RELEASED_START(PSX_PAD1)){
    Serial.println("Released START");
    Serial.write(228);
  }
  if(PRESSED_SELECT(PSX_PAD1)){
    Serial.println("Pressed SELECT");
    Serial.write(231);
  }
  if(RELEASED_SELECT(PSX_PAD1)){
    Serial.println("Released SELECT");
    Serial.write(230);
  }
  readBtns();
}
void readBtns(){
  //btn states:
  BtnGreenState = digitalRead(BtnGreen);
  BtnRedState = digitalRead(BtnRed);
  BtnYellowState = digitalRead(BtnYellow);
  BtnBlueState = digitalRead(BtnBlue);
  BtnOrangeState = digitalRead(BtnOrange);
  if (BtnGreenState != lastButtonStateG) {
    if (BtnGreenState == HIGH) {
      Serial.println("Pressed Green Bnt");
      Serial.write(233);
    }
    else {
      Serial.println("Released Green Bnt");
      Serial.write(232);
    }
    delay(50);
  }
  lastButtonStateG = BtnGreenState;
  if (BtnRedState != lastButtonStateR) {
    if (BtnRedState == HIGH) {
      Serial.println("Pressed Red Bnt");
      Serial.write(235);
    }
    else {
      Serial.println("Released Red Bnt");
      Serial.write(234);
    }
    delay(50);
  }
  lastButtonStateR = BtnRedState;
  if (BtnYellowState != lastButtonStateY) {
    if (BtnYellowState == HIGH) {
      Serial.println("Pressed Yellow Bnt");
      Serial.write(237);
    }
    else {
      Serial.println("Released Yellow Bnt");
      Serial.write(236);
    }
    delay(50);
  }
  lastButtonStateY = BtnYellowState;
  if (BtnBlueState != lastButtonStateB) {
    if (BtnBlueState == HIGH) {
      Serial.println("Pressed Blue Bnt");
      Serial.write(239);
    }
    else {
      Serial.println("Released Blue Bnt");
      Serial.write(238);
    }
    delay(50);
  }
  lastButtonStateB = BtnBlueState;
  if (BtnOrangeState != lastButtonStateO) {
    if (BtnOrangeState == HIGH) {
      Serial.println("Pressed Orange Bnt");
      Serial.write(241);
    }
    else {
      Serial.println("Released Orange Bnt");
      Serial.write(240);
    }
    delay(50);
  }
  lastButtonStateO = BtnOrangeState;
}
