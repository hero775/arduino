// For SPIFFS doc see : https://github.com/esp8266/Arduino/blob/master/doc/filesystem.rst
// 한글설명 https://postpop.tistory.com/97
#include "FS.h"

void setup() {
  Serial.begin(115200);
  Serial.println("\nVery basic Spiffs example, writing 10 lines to SPIFFS filesystem, and then read them back");
  SPIFFS.begin();
  // Next lines have to be done ONLY ONCE!!!!!When SPIFFS is formatted ONCE you can comment these lines out!!
  Serial.println("Please wait 30 secs for SPIFFS to be formatted");
  SPIFFS.format();
  Serial.println("Spiffs formatted");

  File f;
  /*
  // open file for writing
  f = SPIFFS.open("/ssid.txt", "w");
  if (!f) {
      Serial.println("file open failed");
  }
  f.println("ssid1234");
  f.println("pw4567");
  f.close();
  */

  f = SPIFFS.open("/ssid.txt", "r");
  if (!f) {
      Serial.println("file open failed");
  }  Serial.println("====== Reading from SPIFFS file =======");
  String ssid=f.readStringUntil('\n');
  Serial.println("ssid : "+ssid);
  String pw=f.readStringUntil('\n');
  Serial.println("password : "+pw);
  SPIFFS.end();
}

void loop() {
  

}
