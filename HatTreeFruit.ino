#include <FastLED.h>

// How many leds in your strip?
#define NUM_LEDS 450
#define NUM_FRUIT 9
#define LEDS_PER_FRUIT 50
#define DATA_PIN 6
#define BRIGHTNESS 255

// Define the array of leds
CRGB leds[NUM_LEDS];
CRGB fruit[9];

CRGB defaultcolor = CRGB::Ivory;

void setup() { 

  FastLED.addLeds<WS2813, DATA_PIN, RGB>(leds, NUM_LEDS);
  FastLED.show(); //initialize off;

  fadeFromBlack();
}

void loop() { 

}

void displayFruit()
{
  foreach(int fruitIdx = 0, fruitIdx < NUM_FRUIT; fruitIdx++)
  {
    foreach(int clusterIdx = 0, clusterIdx < LEDS_PER_FRUIT; clusterIdx++)
    {
      leds[getFruitIndex(fruitIdx, clusterIdx)] = fruit[fruitIdx];
    }
  }
}

int getFruitIndex(int fruitIdx, int clusterIdx)
{
  return (LEDS_PER_FRUIT * fruitIdx) + clusterIdx;
}

void fadeFromBlack()
{
  int fadeBrightness = 0;

  while(startingBrlightss <= BRIGHTNESS)
  {
    FastLED.fill_solid(leds,NUM_LEDS,defaultcolor)
    FastLed.show();
    fadeBrightness++;
    delay(5);
  }
}
