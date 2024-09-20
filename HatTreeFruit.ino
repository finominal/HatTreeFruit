#include <FastLED.h>

// How many leds in your strip?
#define NUM_LEDS 450
#define DATA_PIN 6
#define BRIGHTNESS 255

class Point
{
public:
  double x;
  double y;
  Point(){};
  Point(double _x, double _y)
  {
    x = _x;
    y = _y;
  };
};

class Fruit
{
public:
  Point location;
  CRGB color;
  Fruit(){};
  Fruit(Point _location)
  {
    location = _location;
  };
};

// Define the array of leds
CRGB leds[NUM_LEDS];

Fruit fruit[] = 
{
  Fruit(Point(0,20)),
  Fruit(Point(13,15)),
  Fruit(Point(20,3)),
  Fruit(Point(17,-10)),
  Fruit(Point(7,-19)),
  Fruit(Point(-7,-19)),
  Fruit(Point(-17,-10)),
  Fruit(Point(-20,3)),
  Fruit(Point(-13,15))
};

#define DEFAULT_COLOR CRGB(255,165,45)

void setup() { 
  delay(1000);
  FastLED.addLeds<WS2813, DATA_PIN, GRB>(leds, NUM_LEDS);

  //fadeFromBlack();
}

void loop() { 
  slowlyAround();
  //setAll(DEFAULT_COLOR);

  delay(1000);
}
