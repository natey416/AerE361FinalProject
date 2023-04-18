int eventDetection(int swipeStren,int hitStren) {
  /*
  eventDetection(x accel, y accel, z accel) as floats
  returns values based on what event is found
  return values:
    0: No hit/idle
    1: xz plane swing
    2: xz axis clash
    3: y axis stab
    4: y axis stab clash
   */
  //x and z are swipe
  //calculate x z vector magnitude
  float Xaccel = CircuitPlayground.motionX();
  float Yaccel = CircuitPlayground.motionY();
  float Zaccel = CircuitPlayground.motionZ();
  
//  String xstr = "X: ";
//  String ystr = " Y: ";
//  String zstr = " Z: ";
//  String newline = "\n";
//  String outString = xstr+Xaccel+ystr+Yaccel+zstr+Zaccel+newline;
//  Serial.print(outString);

  float swipeMag = sqrt(pow(Xaccel,2) + pow(Zaccel,2));
//  String newLine ="\n";
//  String printString = swipeMag + newLine;
//  Serial.print(printString);

  //swipe sound
  if (swipeMag > swipeStren && swipeMag< hitStren) {
    return 1;
  }
  //clash sound
  else if (swipeMag >= hitStren) {
    return 2;
  }
  //stab swipe
  else if (Yaccel > swipeStren && Yaccel < hitStren) {
    return 3;
  }
  //stab hit
  else if (Yaccel > hitStren) {
    return 4;
  }
  //idle
  else {
    return 0;
  }
}
