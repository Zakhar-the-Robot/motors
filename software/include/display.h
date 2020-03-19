#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define TIMESTEP 5000

extern Adafruit_SSD1306 display;
void display_init(void);
void display_print(int l, int r);