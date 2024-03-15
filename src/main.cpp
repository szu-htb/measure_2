#include <Arduino.h>
#include "SHTSensor.h"

#include <BH1750.h>

#include "Wire.h"
//创建对象
SHTSensor sht(SHTSensor::SHT3X);
BH1750 lightMeter(0x23);

void BH1750_Init();
void Wire_Init();


void setup() 
{
  Wire.begin(22,21);
  Serial.begin(9600);
  delay(100); // let serial console settle

  Wire_Init();
  BH1750_Init();
}

void loop() {
  //温湿度
  if (sht.readSample()) 
  {
      Serial.print("SHT:\n");
      Serial.printf("  RH: %.2f %%\n",sht.getHumidity());
      Serial.printf("  T:  %.2f C\n",sht.getTemperature());
  } 
  else {
      Serial.print("Error in readSample()\n");
  }

  delay(1000);
  //光敏
  if (lightMeter.measurementReady()) 
  {
    Serial.printf("Light: %.2f lx\n",lightMeter.readLightLevel());
  }
  delay(1000);
}

void BH1750_Init()
{
  if (lightMeter.begin(BH1750::CONTINUOUS_HIGH_RES_MODE)) {
    Serial.println(F("BH1750 Advanced begin"));
  } else {
    Serial.println(F("Error initialising BH1750"));
  }
}

void Wire_Init()
{
  sht.setAccuracy(SHTSensor::SHT_ACCURACY_MEDIUM); // only supported by SHT3x
  if (sht.init()) {
     Serial.print("sht.init(): success\n");
  } else {
    Serial.print("sht.init(): failed\n");
  }
}