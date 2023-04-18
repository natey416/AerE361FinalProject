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
  
  }
  delay(delayTime);
}
