#include <PubSubClient.h>
#include <WiFi.h>
//json��ʽ����
#include <ArduinoJson.h>

extern WiFiClient espClient;//wifi����
extern PubSubClient client;
extern 
//wifi��ʼ��
void Wifi_Init();
//�ӵ�������Ϣ�Ļص�����
void callback(char* topic, byte* payload, unsigned int length);
//����
void reconnect();
//������Ϣ
void mqtt_Send();