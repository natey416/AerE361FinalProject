#include <Adafruit_NeoPixel.h>
#include <Adafruit_CircuitPlayground.h>
#include <math.h>

//neopixel defines
#define LED_PIN A1
#define LED_COUNT 30
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

// colors
uint32_t red = strip.Color(255, 0, 0);
uint32_t magenta = strip.Color(255, 0, 255);
uint32_t offmagenta = strip.Color(200, 0, 200);
uint32_t white = strip.Color(255, 255, 255);
//used colors defines
#define DEFAULTCOLOR magenta
#define FLASHCOLOR white
#define SWINGCOLOR red

//IMU SETTINGS
#define SWINGSTRENGTH 20
#define CLASHSTRENGTH 35

#define DELAYTIME 10


void setup() {
  // put your setup code here, to run once:
  CircuitPlayground.begin();
  Serial.begin(9600);
  CircuitPlayground.setAccelRange(LIS3DH_RANGE_4_G);
  strip.begin();
}

void loop() {

  // put your main code here, to run repeatedly:
  int event = 0;
  event = eventDetection(SWINGSTRENGTH, CLASHSTRENGTH);
  switch (event) {
    case 0:
      strip.fill(DEFAULTCOLOR);
      //CircuitPlayground.playTone(200, 1000, true);
      break;
    case 1:
      Serial.print("Swipe");
      Serial.print("\n");
      //CircuitPlayground.playTone(400, 1000, true);
      swingFlash();
      break;
    case 2:
      Serial.print("Clash");
      Serial.print("\n");
      //CircuitPlayground.playTone(600, 1000, true);
      clashFlash();
      break;
    default:
      break;
  }

  // delay(DELAYTIME);
  strip.show();
}
