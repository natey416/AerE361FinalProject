void clashFlash() {
  strip.fill(FLASHCOLOR);
  strip.show();
  delay(100);
  strip.fill(DEFAULTCOLOR);
  strip.show();
  delay(100);
  strip.fill(FLASHCOLOR);
  strip.show();
  delay(100);
  strip.fill(DEFAULTCOLOR);
  strip.show();
  delay(100);
  strip.fill(FLASHCOLOR);
  strip.show();
  delay(100);
  strip.fill(DEFAULTCOLOR);
  strip.show();
  delay(100);
}

void swingFlash() {
  strip.fill(SWINGCOLOR);
  strip.show();
  delay(100);
}