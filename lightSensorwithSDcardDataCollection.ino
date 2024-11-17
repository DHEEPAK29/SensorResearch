#include "DEV_Config.h"
#include "LTR390.h"
#include <SD.h>
 
File myFile;
int x = 0;

UDOUBLE UV,ALS;

void setup() {
  Serial.begin(9600);
  pinMode(53, OUTPUT);
  myFile = SD.open("uvTesting.txt", FILE_WRITE);
  // SD.begin(53);

  if(LTR390_Init() != 0){
      Serial.print("init err!!!");
      while(1);
  }
  LTR390_SetIntVal(5, 20);

}

void loop() {
  // while (x<10) {
  //   UV = LTR390_UVS();
  //   Serial.print("UV = ");
  //   Serial.println(UV);
  //   myFile.print("UV = ");
  //   myFile.println(UV);
  //   DEV_Delay_ms(500);

  //   x += 1;
  // }
  // if (x = 10){
  //   myFile.close();
  // }
  UV = LTR390_UVS();
  Serial.print("UV = ");
  Serial.println(UV);
  myFile.print("UV = ");
  myFile.println(UV);
  DEV_Delay_ms(500);

  x++;

  if (x == 10) {
    myFile.close();
  }

  // while (x=10){
  //   myFile.close();
  //   x += 1;
  // }

    /ALS = LTR390_ALS();
    Serial.print("ALS = ");
    Serial.println(ALS);
    DEV_Delay_ms(500);/

}
