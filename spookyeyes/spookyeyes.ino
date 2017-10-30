#include <Adafruit_NeoPixel.h>

#define LED_PIN 10
#define MOTION_PIN 8
#define SOUND_PIN 7

enum {
  Red = 0xFF0000,
  Green = 0x00FF00,
  Blue = 0x0000FF,
  Yellow = 0xFFFF00,
  Purple = 0x800080,
  Aqua = 0x00FFFF
};

enum {
  Eye1 = 0,
  Eye2,
  Eye3,
  Eye4,
  Eye5,
  Eye6,
  EyeTotal
};

Adafruit_NeoPixel leds = Adafruit_NeoPixel(EyeTotal, LED_PIN, NEO_GRB + NEO_KHZ800);

void clear()
{
  for (int i=0; i<EyeTotal; i++)
  {
    leds.setPixelColor(i, 0);
  }
   leds.show();
}

void allOn()
{
  leds.setPixelColor(Eye1, Red);   
  leds.show();
  leds.setPixelColor(Eye2, Green);
  leds.show();
  leds.setPixelColor(Eye3, Yellow);
  leds.show();
  leds.setPixelColor(Eye4, Blue);
  leds.show();
  leds.setPixelColor(Eye5, Purple);
  leds.show();
  leds.setPixelColor(Eye6, Aqua);
  leds.show();
}

void selfTest()
{
  allOn();
  delay(5000);
}

void setup() {
 
  pinMode(MOTION_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(SOUND_PIN, OUTPUT);
  
  leds.begin();
  clear();
}

void loop() {
  static bool once = true;

  if (once)
  {
    selfTest();
    once = false;
  }

  if (!digitalRead(MOTION_PIN))
  {
    leds.setPixelColor(Eye1, Red);   
    leds.show();
    delay(500);
    
    digitalWrite(SOUND_PIN, 1);
    leds.setPixelColor(Eye2, Red);
    leds.show();
    delay(300);
    
    digitalWrite(SOUND_PIN, 0);
    leds.setPixelColor(Eye3, Yellow);
    leds.show();
    delay(200);
    leds.setPixelColor(Eye1, 0);   
    leds.show();
    delay(100);
    
    leds.setPixelColor(Eye4, Yellow);
    leds.show();
    delay(2000);

    leds.setPixelColor(Eye1, 0);   
    leds.show();
    leds.setPixelColor(Eye5, Red);
    leds.show();
     leds.setPixelColor(Eye6, Yellow);
    leds.show();
    delay(2000);
    
    leds.setPixelColor(Eye1, 0);
    leds.show();
    delay(300);
    leds.setPixelColor(Eye2, 0);
    leds.show();
    delay(1500);
    leds.setPixelColor(Eye3, 0);
    leds.show();
    leds.setPixelColor(Eye4, 0);
    leds.show();
    delay(300);
    leds.setPixelColor(Eye5, 0);
    leds.show();
    leds.setPixelColor(Eye6, 0);
    leds.show();

    delay(8000);
  }
}


