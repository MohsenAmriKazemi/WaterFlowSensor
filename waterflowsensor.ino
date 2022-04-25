int X;
int Y;
float TIME = 0;
float FREQUENCY = 0;
float WATER = 0;
float TOTAL = 0;
float LM = 0;
char input = A5;
int var = 1; 
const String st0 = "Not using";
const String st1 = "Proper use";
const String st2 = "Limit";
const String st3 = "Excess";
const String st4 = "XX L/s";
const String st5 = "YY L/s";
const String st6 = "ZZ L/s";
const String st7 = "Good Citizen";
const String st8 = "In average";
const String st9 = "Waster!";
const String st10 = "Sustainable";
const String st11 = "In average";
const String st12 = "-";
const String st13 = "Thanks!";
const String st14 = "Think of \n others";
const String st15 = "Ey!";
String mm = st0;
String prmm = mm;
String nn = "Political Values";
int prV = var;

#include <Arduino_MKRIoTCarrier.h>
MKRIoTCarrier carrier;
uint32_t green = carrier.leds.Color(255,0,0);
uint32_t yellow = carrier.leds.Color(230,255,0);
uint32_t red = carrier.leds.Color(0,255,0);
uint32_t off = carrier.leds.Color(0,0,0);


void setup(){
Serial.begin(9600);
pinMode(input,INPUT);
CARRIER_CASE = true;
carrier.begin();
carrier.display.init(240, 240);
carrier.display.setRotation(0);
delay(1500);

}

void loop1(){
     carrier.Buttons.update();	// Read the buttons state
   
   //Check if the Button 0 is being touched
   if (carrier.Buttons.getTouch(TOUCH0)){
      var = 1;
      nn = "Political Values";

   }
  if (carrier.Buttons.getTouch(TOUCH1)){
      var = 2;
      nn = "Economical Values";

   }
     if (carrier.Buttons.getTouch(TOUCH2)){
      var = 3;
      nn = "Social Values";

   }
     if (carrier.Buttons.getTouch(TOUCH3)){
      var = 4;
      nn = "Environmental \n Values";

   }
     if (carrier.Buttons.getTouch(TOUCH4)){
      var = 5;
      nn = "Emotional Values";

      }
      if (prV != var){updateText();}
      prV = var;

                if (TIME<0.01){
   carrier.leds.fill(off, 0, 5);
   carrier.leds.show();
    }
}


void loop2(){
loop1();
X = pulseIn(input, HIGH);
loop1();
Y = pulseIn(input, LOW);
loop1();
TIME = X + Y;

FREQUENCY = 1000000/TIME;
WATER = FREQUENCY/7.5;

LM = WATER/60;

if(FREQUENCY >= 0){

if(isinf(FREQUENCY)){
  mm = st0;
}
else
{
TOTAL = TOTAL + LM;
switch (var) {

  case 1:
      if (WATER<5){
carrier.leds.fill(green, 0, 5);
carrier.leds.show();
mm = st1;
} else if( WATER >= 5 && WATER < 10) {
carrier.leds.fill(yellow, 0, 5);
carrier.leds.show();
mm = st2;
  } else {
carrier.leds.fill(red, 0, 5);
carrier.leds.show();
mm = st3;}
    break;

  case 2:
      if (WATER<5){
carrier.leds.fill(green, 0, 5);
carrier.leds.show();
mm = st4;
} else if( WATER >= 5 && WATER < 10) {
carrier.leds.fill(yellow, 0, 5);
carrier.leds.show();
mm = st5;
  } else {
carrier.leds.fill(red, 0, 5);
carrier.leds.show();
mm = st6;}
    break;

  case 3:
      if (WATER<5){
carrier.leds.fill(green, 0, 5);
carrier.leds.show();
mm = st7;
} else if( WATER >= 5 && WATER < 10) {
carrier.leds.fill(yellow, 0, 5);
carrier.leds.show();
mm = st8;
  } else {
carrier.leds.fill(red, 0, 5);
carrier.leds.show();
mm = st9;}
    break;

  case 4:
      if (WATER<5){
carrier.leds.fill(green, 0, 5);
carrier.leds.show();
mm = st10;
} else if( WATER >= 5 && WATER < 10) {
carrier.leds.fill(yellow, 0, 5);
carrier.leds.show();
mm = st11;
  } else {
carrier.leds.fill(red, 0, 5);
carrier.leds.show();
mm = st12;}
    break;

  case 5:
      if (WATER<5){
carrier.leds.fill(green, 0, 5);
carrier.leds.show();
mm = st13;
} else if( WATER >= 5 && WATER < 10) {
carrier.leds.fill(yellow, 0, 5);
carrier.leds.show();
mm = st14;
  } else {
carrier.leds.fill(red, 0, 5);
carrier.leds.show();
mm = st15;}
    break;

  default:

    Serial.println("Default");
    break;

}}
if (prmm != mm){
  updateText();
} 
prmm = mm;
}}

void updateText() {
  carrier.display.fillScreen(ST77XX_BLACK);
  carrier.display.setTextSize(3);
   carrier.display.setCursor(55, 120);
  carrier.display.print(mm);
  carrier.display.setTextSize(2);
  carrier.display.setCursor(30, 60);
  carrier.display.print(nn);
}

void loop(){
  loop2();
  Serial.println(mm);

}

