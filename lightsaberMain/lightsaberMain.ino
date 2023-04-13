#include <Adafruit_CircuitPlayground.h>
#include <math.h>
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  CircuitPlayground.begin();
  CircuitPlayground.setAccelRange(LIS3DH_RANGE_4_G);

}

void loop() {
  int delayTime = 50;
  // put your main code here, to run repeatedly:
  float Xaccel = CircuitPlayground.motionX();
  float Yaccel = CircuitPlayground.motionY();
  float Zaccel = CircuitPlayground.motionZ();
  String xstr = "X: ";
  String ystr = " Y: ";
  String zstr = " Z: ";
  String newline = "\n";
  String outString = xstr+Xaccel+ystr+Yaccel+zstr+Zaccel+newline;
  //Serial.print(outString);

  hitDetection(Xaccel,Yaccel,Zaccel);
  delay(delayTime);
}
