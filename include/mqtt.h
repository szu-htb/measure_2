#include <PubSubClient.h>
#include <WiFi.h>
//json格式数据
#include <ArduinoJson.h>

extern WiFiClient espClient;//wifi对象
extern PubSubClient client;
extern 
//wifi初始化
void Wifi_Init();
//接到发布信息的回调函数
void callback(char* topic, byte* payload, unsigned int length);
//重连
void reconnect();
//发送信息
void mqtt_Send();