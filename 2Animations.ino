#define NUM_FRUIT 9
#define LEDS_PER_FRUIT 1

double distanceBetween(Point a, Point b)
{
  double xab = a.x - b.x;
  double yab = a.y - b.y;

  double distance = sqrt( sq(xab) + sq(yab) );

  return abs(distance);
};

void slowlyAround()
{
  int frames = 1024;
  int frameNo = 0;

  while(frameNo < frames)
  {
    Point sun = orbit[frameNo];

    for(int i = 0; i<NUM_FRUIT; i++)
    {
      double distance = distanceBetween(sun, fruit[i].location);
      fruit[i].color = DEFAULT_COLOR.fadeLightBy(distance * 6);
    }

    displayFruit();

    frameNo++;
  }

}

void setAll(CRGB color)
{
  for(int fruitIdx = 0; fruitIdx < NUM_FRUIT; fruitIdx++)
  {
    fruit[fruitIdx].color = color;
  }

  displayFruit();
}

void displayFruit()
{
  for(int fruitIdx = 0; fruitIdx < NUM_FRUIT; fruitIdx++)
  {
    for(int clusterIdx = 0; clusterIdx < LEDS_PER_FRUIT; clusterIdx++)
    {
      leds[calcFruitIndex(fruitIdx, clusterIdx)] = fruit[fruitIdx].color;
    }
  }
  FastLED.show();
}

int calcFruitIndex(int fruitIdx, int clusterIdx)
{
  return (LEDS_PER_FRUIT * fruitIdx) + clusterIdx;
}

void fadeFromBlack()
{
  int fadeBrightness = 0;
  FastLED.setBrightness(fadeBrightness);

  while(fadeBrightness < BRIGHTNESS)
  {

    for(int fruitIdx = 0; fruitIdx < NUM_FRUIT; fruitIdx++)
    {
      fruit[fruitIdx].color = DEFAULT_COLOR;
    }

    displayFruit();
    
    fadeBrightness++;
    FastLED.setBrightness(fadeBrightness);

    delay(4);
  }

  //finally, set the fixed brightness
  FastLED.setBrightness(BRIGHTNESS);
}


