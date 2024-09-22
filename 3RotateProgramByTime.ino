
/* NOT IN USE - Using Power cycle changes */


//Call This method
void RotateProgram()
 {
   if(programChangeTime < millis())
    {
      Serial.println("Rotate");
      switch(currentProgram)
      {
        case still1:
          currentProgram = slow;
          break;
        case slow: 
          currentProgram = still2;
          break;
        case still2:
          currentProgram = fast;
          break;
        case fast: 
          currentProgram = still1;
          break;
      }
      Serial.println(currentProgram); 
      SetNextProgramChangeTime();
    }
 }

void SetNextProgramChangeTime()
{
   switch(currentProgram)
  {
    case still1:
    case still2:
      SetProgramChangeTime(stillRunTime);
      break;
    case slow:
      SetProgramChangeTime(slowRunTime);
      break;
    case fast:
      SetProgramChangeTime(fastRunTime);
      break;
  } 
}

void SetProgramChangeTime(uint32_t runtimeMs)
{
  programChangeTime = millis() + (runtimeMs);
  Serial.print("programChangeTime="); Serial.println(programChangeTime);
}