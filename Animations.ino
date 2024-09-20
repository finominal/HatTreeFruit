#define NUM_FRUIT 9
#define LEDS_PER_FRUIT 1

void slowlyAround()
{
  int frames = 1024;
  int frameNo = 0;
  while(frameNo < frames)
  {
    Circle c = Circle[frameNo]; //get

    for(int i = 0; i<NUM_FRUIT; i++)
    {
 
      double distance = 
    }
  }
}


void displayDefaultColor()
{
    for(int fruitIdx = 0; fruitIdx < NUM_FRUIT; fruitIdx++)
    {
      fruit[fruitIdx].color = defaultcolor;
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
      fruit[fruitIdx].color = defaultcolor;
    }

    displayFruit();
    
    fadeBrightness++;
    FastLED.setBrightness(fadeBrightness);

    delay(4);
  }

  //finally, set the fixed brightness
  FastLED.setBrightness(BRIGHTNESS);
}


