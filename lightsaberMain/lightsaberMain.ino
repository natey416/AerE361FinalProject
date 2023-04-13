#include <Adafruit_CircuitPlayground.h>
#include <math.h>
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  CircuitPlayground.begin();
  CircuitPlayground.setAccelRange(LIS3DH_RANGE_4_G);
}

void loop() {
  int delayTime = 100;
  // put your main code here, to run repeatedly:
  int event = eventDetection(20,30);
  switch (event) {
    case 1:
      Serial.print("Swipe detected!\n");
      break;
    case 2:
      Serial.print("Clash Detected!\n");
      break;
    case 3:
      Serial.print("Stab detected!\n");
      break;
    case 4:
      Serial.print("Stab clash detected!\n");
      break;
    default:
      //defualts
      break;  
  }
  delay(delayTime);
}
