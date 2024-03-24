//传感器头文件
#include "sensor.h"
#include "soil.h"
//mqtt头文件
#include "mqtt.h"
//wifi_Smartconfig
#include"smartconfig.h"

// void Wifi_Init();
// //接到发布信息的回调函数
// void callback(char* topic, byte* payload, unsigned int length);
// //重连
// void reconnect();


void setup() 
{
  sensor_Init();
  Serial.begin(9600);   //串口后期可优化
  delay(100); // let serial console settle
  //Wifi_Init();
  delay(100);
  if (!AutoConfig())
  {
  SmartConfig();
  }
  esp_wifi_restore();
}
// //创建JSON对象
// JsonDocument Data;
// String input = "{\"sensor\":\"SHT3X\",\"time\":1351824120,\"data\":[48.756080,2.302038]}";

void loop() 
{
  sensor_Start();
  //WIFI检测循环
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
  //发送信息
  mqtt_Send();
}
