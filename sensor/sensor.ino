#define OLED

#ifdef OLED
  #include <Wire.h>
  #include <SFE_MicroOLED.h>
  #define PIN_RESET 255
  #define DC_JUMPER 0
  MicroOLED oled(PIN_RESET, DC_JUMPER);
#endif

int EC = 0;
int ECthresh = 300;
int motorPin = D3;

void setup()
{
#ifdef OLED
  oled.begin();
  oled.clear(ALL);
#endif
  
  pinMode(motorPin, OUTPUT);
}

void loop()
{
  EC = analogRead(A0);
  
#ifdef OLED
  oled.setFontType(0);
  oled.setCursor(0, 0); 
  oled.print(EC);
  oled.setCursor(0, 10); 

  if (EC > ECthresh)
  {
    //send message to turn pump on
    
    //digitalWrite(motorPin, HIGH);
    //delay(3000);
    //digitalWrite(motorPin, LOW);
    //delay(3000);  
    
    oled.print("on");
  }
  else
  {
    oled.print("off");
  }
  oled.display();   
#endif

}
