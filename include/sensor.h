#include <BH1750.h>   //光敏传感器
#include "Wire.h"     //I2C
#include "SHTSensor.h"    //SHT3X
#include <Arduino.h>

//光敏电阻初始化
void BH1750_Init();
//温湿度传感器初始化
void Wire_Init();

void sensor_Start();

void sensor_Init();