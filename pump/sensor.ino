#define OLED

#ifdef OLED
  #include <Wire.h>
  #include <SFE_MicroOLED.h>
  #define PIN_RESET 255
  #define DC_JUMPER 0
  MicroOLED oled(PIN_RESET, DC_JUMPER);
#endif

int EC = 0;
int motorPin = D3;

void setup()
{
#ifdef OLED
  oled.begin();
  oled.clear(ALL);  // Clear the display's memory (gets rid of artifacts)
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

  if (EC > 300)
  {
    digitalWrite(motorPin, HIGH);   // sets the LED on
    delay(3000);                  // waits for a second
    digitalWrite(motorPin, LOW);    // sets the LED off
    delay(3000);  
    
    oled.print("on");
  }
  else
  {
    oled.print("off");
  }
  oled.display();   
#endif

}
