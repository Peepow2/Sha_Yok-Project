// Fill-in information from your Blynk Template here
#define BLYNK_TEMPLATE_ID "TMPLkDSDch1s"
#define BLYNK_DEVICE_NAME "Plant a tree automation"
#define BLYNK_FIRMWARE_VERSION        "0.1.0"
 
#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG
 
#define APP_DEBUG
 
// Uncomment your board, or configure a custom board in Settings.h
//#define USE_SPARKFUN_BLYNK_BOARD
//#define USE_NODE_MCU_BOARD
//#define USE_WITTY_CLOUD_BOARD
//#define USE_WEMOS_D1_MINI
 
#include "BlynkEdgent.h"
int analogpin = A0;
int val = 0;
bool MoreThan800 = False, prevMoreThan800 = False;
const byte relay = D2;
 
void setup()
{
  Serial.begin(115200);
  pinMode(relay, OUTPUT);
  BlynkEdgent.begin();
  BlynkEdgent.run();
}
 
void loop() {
  MoreThan800 = analogRead(analogpin) > 800;
  Serial.print("val =     ");
  Serial.println(val);
  Blynk.virtualWrite(V0, val);
  
  if (MoreThan800)
      digitalWrite(relay, HIGH);
  else
      digitalWrite(relay, LOW);
}
