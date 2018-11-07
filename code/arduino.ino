#include <Adafruit_NeoPixel.h>
#include <Servo.h>

Servo myservo;

#define PIN 6
int signalState;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(9, PIN, NEO_GRB + NEO_KHZ800);

int red[3]    = { 255, 0, 0 };
int yellow[3]    = { 255, 255, 0 };
int green[3]    = { 0, 255, 0 };
int blue[3]    = { 0, 0, 255 };
int purple[3]    = { 80, 0, 80 };
int aqua[3]    = { 0, 255, 255 };
int pink[3]    = { 255, 153, 255 };
int off[3]    = { 0, 0, 0 };


void setup() {

  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(10, OUTPUT);
  myservo.attach(9);
  myservo.write(90);

  strip.begin();
  strip.show();
}


void loop() {
  while(Serial.available() > 0 ) {
    String str = Serial.readString();
    if(str.indexOf("face_on") > -1) { digitalWrite(2, HIGH); }
    if(str.indexOf("face_off") > -1) { digitalWrite(2, LOW); }
    if(str.indexOf("furby_face") > -1) { furby_face(); }
    if(str.indexOf("furby_up") > -1) { furby_up(); }
    if(str.indexOf("furby_down") > -1) { furby_down(); }
    if(str.indexOf("furby_happy") > -1) { furby_happy(); }
    if(str.indexOf("beat") > -1) { beat(red); }
    if(str.indexOf("red") > -1) { neocolor(red); }
    if(str.indexOf("red2") > -1) { neocolor2(red); } 
    if(str.indexOf("yellow") > -1) { neocolor(yellow); }
    if(str.indexOf("green") > -1) { neocolor(green); }
    if(str.indexOf("blue") > -1) { neocolor(blue); }
    if(str.indexOf("purple") > -1) { neocolor(purple); }
    if(str.indexOf("aqua") > -1) { neocolor(aqua); }
    if(str.indexOf("pink") > -1) { neocolor(pink); }
    if(str.indexOf("neo_off") > -1) { neocolor(off); }
    if(str.indexOf("rainbow1") > -1) { rainbow(20); neocolor(off); }
    if(str.indexOf("rainbow2") > -1) { rainbowCycle(20); neocolor(off); }
    if(str.indexOf("rainbow3") > -1) { theaterChaseRainbow(50); neocolor(off); }
    if(str.indexOf("3") > -1) { theaterChase(strip.Color(127, 0, 0), 50); }
    if(str.indexOf("delay_1000") > -1) { delay(1000); }
    if(str.indexOf("delay_random") > -1) { delay(random(3,20)*100); }   
    else { Serial.println("unknown"); }
  }
}

void furby_up() { myservo.write(120); }
void furby_down() { myservo.write(90); }

void furby_happy() {
  uint16_t f;
  for (f=0; f<5; f++) {
    myservo.write(120);
    delay(200);
    myservo.write(90);
    delay(200); }
  myservo.write(120);
}

void furby_face() {
  digitalWrite(2, HIGH);
  delay(random(5,20)*100);
  digitalWrite(2, LOW);
}

void neocolor(int color[3]) { colorWipe(strip.Color(color[0], color[1], color[2]), 50); }
void neocolor2(int color[3]) { theaterChase(strip.Color(color[0], color[1], color[2]), 50); }

void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

void beat (int color[3]) {
   uint16_t ii,i;
   for (ii = 0; ii < 7; ii++) {
    int beatrandom = random(3,10)*100;
    for (i = 0; i < strip.numPixels(); i++) { strip.setPixelColor(i,strip.Color(color[0], color[1], color[2])); }
    strip.show();
    delay(beatrandom);
    for (i = 0; i < strip.numPixels(); i++) { strip.setPixelColor(i,0,0,0); }
    strip.show();
    delay(beatrandom/random(2,4));
   }
}

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

void theaterChase(uint32_t c, uint8_t wait) {
  for (int j=0; j<10; j++) {  //do 10 cycles of chasing
    for (int q=0; q < 3; q++) {
      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, c);    //turn every third pixel on
      }
      strip.show();
      delay(wait);
      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

void theaterChaseRainbow(uint8_t wait) {
  for (int j=0; j < 256; j++) {     // cycle all 256 colors in the wheel
    for (int q=0; q < 3; q++) {
      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, Wheel( (i+j) % 255));    //turn every third pixel on
      }
      strip.show();
      delay(wait);
      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}

