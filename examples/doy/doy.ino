#include <Wire.h>
#include "RTClib.h"
RTC_DS1307 rtc;
int doy;

void setup()
{
  Serial.begin(9600);
  Wire.begin();
  rtc.begin();
  if (! rtc.isrunning())
  {
    Serial.println(F("RTC  NOT running!")); // error message
  }
  // This line sets the RTC with an explicit date & time, for example to set
  // January 30, 2015 at 22:50 pm you would call:
  //rtc.adjust(DateTime(2015, 1, 30, 22, 25, 0));
  //rtc.adjust(DateTime(2016, 5, 3, 22, 12, 0));
  DateTime now = rtc.now();
  DateTime compiled = DateTime(__DATE__, __TIME__);
  if (now.unixtime() < compiled.unixtime())
  {
    Serial.print(F("Current Unix time"));
    Serial.println(now.unixtime());
    Serial.print(F("Compiled Unix time"));
    Serial.println(compiled.unixtime());
    Serial.println(F("RTC is older than compile time! Updating"));
    // following line sets the RTC to the date & time this sketch was compiled
    // rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
  rtc.writeSqwPinMode(SquareWave1HZ); // sets the SQW output to 1 Hz, which can be used for a signal function
}
void loop()
{
  DateTime now = rtc.now();

  doy = now.dayOfYear();
  Serial.print(doy);
}
