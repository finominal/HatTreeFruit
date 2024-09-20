#include <FastLED.h>

// How many leds in your strip?
#define NUM_LEDS 450
#define DATA_PIN 6
#define BRIGHTNESS 255

class Fruit
{
public:
  int x;
  int y;
  CRGB color;
  Fruit(int _x, int _y)
  {
    x = _x;
    y = _y;
  };
};

// Define the array of leds
CRGB leds[NUM_LEDS];
Fruit fruit[] = 
{
  Fruit(0,20),
  Fruit(13,15),
  Fruit(20,3),
  Fruit(17,-10),
  Fruit(7,-19),
  Fruit(-7,19),
  Fruit(-17,-10),
  Fruit(-20,3),
  Fruit(-13,15)
};

CRGB defaultcolor = CRGB(255,165,45);


void setup() { 
  delay(1000);
  FastLED.addLeds<WS2813, DATA_PIN, GRB>(leds, NUM_LEDS);

  //fadeFromBlack();
}

void loop() { 

  displayDefaultColor();

  delay(1000);
}

/******** Helpers ***********/

