#include <Adafruit_CircuitPlayground.h>
#include <math.h>

void hitDetection(float x,float y,float z) {
  //x and z are swipe
  //calculate x z vector magnitude
  float swipeMag = sqrt(pow(x,2) + pow(z,2));
  String newLine ="\n";
  String printString = swipeMag + newLine;
  //Serial.print(printString);
  if (swipeMag > 25 && swipeMag< 50) {
    Serial.print
  }
  
  //Y is stab
}
