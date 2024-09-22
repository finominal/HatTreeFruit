#include <FastLED.h>

// How many leds in your strip?
#define NUM_LEDS 450
#define DATA_PIN 6
#define BRIGHTNESS 255
#define NUM_FRUIT 9
#define LEDS_PER_FRUIT 1

//ProgramRotation
#define STATIC_RUN_MINUTES 5
#define SLOWROUND_RUN_MINUTES 1
#define FASTROUND_RUN_MINUTES 1
#define MINUTE_MULTIPLIER 1000

uint32_t stillRunTime = STATIC_RUN_MINUTES * MINUTE_MULTIPLIER; 
uint32_t slowRunTime = SLOWROUND_RUN_MINUTES * MINUTE_MULTIPLIER; 
uint32_t fastRunTime = FASTROUND_RUN_MINUTES * MINUTE_MULTIPLIER; 
uint32_t programChangeTime = stillRunTime;

enum FadeDirection {In, Out};

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

  //start gentle
  fadeFromBlack();
  fastAround(250, true, In);
  fastAround(250, false, In);
}

int lastSize = 380;
void loop() { 
  
  RotateProgram();
  Serial.print("currentProgram:"); Serial.println(currentProgram);
  //currentProgram = fast;
  switch(currentProgram)
  {
    case still1:
      fastAround(250, true, Out);
      setAll(DEFAULT_COLOR);
      delay(stillRunTime);
      break;
    case slow:
      slowAround(380, true, In);
      slowAround(380, false, In);
      break;
    case still2: 
      slowAround(380, true, Out);
      setAll(DEFAULT_COLOR);
      delay(stillRunTime);
      break;
    case fast: 
      fastAround(250, true, In);
      fastAround(250, false, In);
      break;
  }

}

void Transition(Point* from, Point* to, int percentage)
{

}
