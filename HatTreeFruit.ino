#include <FastLED.h>

// How many leds in your strip?
#define NUM_LEDS 450
#define DATA_PIN 6
#define BRIGHTNESS 255
#define NUM_FRUIT 9
#define LEDS_PER_FRUIT 1

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
  Fruit(Point(0,200)),
  Fruit(Point(130,150)),
  Fruit(Point(200,30)),
  Fruit(Point(170,-100)),
  Fruit(Point(70,-190)),
  Fruit(Point(-70,-190)),
  Fruit(Point(-170,-100)),
  Fruit(Point(-200,30)),
  Fruit(Point(-130,150))
};

CRGB fruitBuffer[NUM_FRUIT];

#define DEFAULT_COLOR CRGB(255,165,45)

//programSelection 
enum PROGRAM {still1, slow, still2, fast }; //remember to match numberOfPrograms
PROGRAM currentProgram = still1;
const int numberOfPrograms = 4; //no way to count enums. 

void setup() { 
  delay(1000);

  Serial.begin(115200);
  Serial.println("BEGIN!");
  
  FastLED.addLeds<WS2813, DATA_PIN, GRB>(leds, NUM_LEDS);

  fadeFromBlack();
}

void loop() { 
  
  //RotateProgram();
  Serial.print("currentProgram:"); Serial.println(currentProgram);
  currentProgram = fast;
  switch(currentProgram)
  {
    case still1:
      setAll(DEFAULT_COLOR);
      delay(1000);
      break;
    case slow:
      slowAround(380);
      break;
    case still2: 
      setAll(DEFAULT_COLOR);
      break;
    case fast: 
      fastAround(random(250,380));
      break;
  }

}

void Transition(Point* from, Point* to, int percentage)
{

}
