#include <BH1750.h>   //����������
#include "Wire.h"     //I2C
#include "SHTSensor.h"    //SHT3X
#include <Arduino.h>

//���������ʼ��
void BH1750_Init();
//��ʪ�ȴ�������ʼ��
void Wire_Init();

void sensor_Start();

void sensor_Init();