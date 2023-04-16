#include <Adafruit_CircuitPlayground.h>

const int NUM_OF_PIXELS = 30;
const int ON_BUTTON = A1;
const int COLOR_BUTTON = A2;

uint32_t RED;  // red
uint32_t ORANGE;
uint32_t YELLOW;
uint32_t GREEN;  // green
uint32_t BLUE;  // blue
uint32_t INDIGO;
uint32_t VIOLET;
uint32_t WHITE;  // white

const uint32_t colors[] = {RED, ORANGE, YELLOW, GREEN, BLUE, INDIGO, VIOLET, WHITE};

bool saber_on = false;
int current_color_index = 7;

void set_pixel_color(int pixel_index, uint32_t color) {
  CircuitPlayground.strip.setPixelColor(pixel_index, color);
  CircuitPlayground.strip.show();
}

void setup() {
  Serial.begin(9600);

  CircuitPlayground.begin();
  pinMode(ON_BUTTON, INPUT_PULLUP);
  pinMode(COLOR_BUTTON, INPUT_PULLUP);

  CircuitPlayground.setPixelColor(0,255, 0, 0);
  CircuitPlayground.setPixelColor(1,255, 40, 0);
  CircuitPlayground.setPixelColor(2,255, 150, 0);
  CircuitPlayground.setPixelColor(3,0, 255, 0);
  CircuitPlayground.setPixelColor(4,0, 0, 255);
  CircuitPlayground.setPixelColor(5,63, 0, 255);
  CircuitPlayground.setPixelColor(6,127, 0, 255);
  CircuitPlayground.setPixelColor(7,255, 255, 255);
}

void loop() {
  // check if the on button is pressed
  if (digitalRead(ON_BUTTON) == LOW && !saber_on) {
    saber_on = turn_saber_on(1000);
  } else if (digitalRead(ON_BUTTON) == LOW && saber_on) {
    saber_on = turn_saber_off(1000, current_color_index);
  }

  // check if the color button is pressed
  if (digitalRead(COLOR_BUTTON) == LOW) {
    current_color_index = change_color(current_color_index);
  }
}

// function to turn lightsaber on
bool turn_saber_on(int press_time) {
  Serial.println("Lightsaber is turning on!");
  bool saber_on = true;

  // turn on lights from bottom to top
  for (int i = 0; i < 15; i++) {
    set_pixel_color(i, colors[current_color_index]);
    set_pixel_color(NUM_OF_PIXELS - 1 - i, colors[current_color_index]);
    delay(press_time/30); // slow down loop based on button press time
  }

  return saber_on;
}

// function to turn lightsaber off
bool turn_saber_off(int press_time, int current_color_index) {
  Serial.println("Lightsaber is turning off :");
  bool saber_on = false;

  // turn off lights from top to bottom
  for (int i = 14; i >= 0; i--) {
    set_pixel_color(i, 0);
    set_pixel_color(NUM_OF_PIXELS - 1 - i, 0);
delay(press_time/30); // slow down loop based on button press time
}

return saber_on;
}

// function to change color
int change_color(int current_color_index) {
current_color_index = (current_color_index + 1) % 8;
Serial.print("Color changed to: ");
Serial.println(current_color_index);
return current_color_index;
}