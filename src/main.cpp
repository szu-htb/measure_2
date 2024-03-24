//传感器头文件
#include "sensor.h"
#include "soil.h"
//mqtt头文件
#include "mqtt.h"


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
  Wifi_Init();
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


// void Wifi_Init()
// {
//   delay(10);
//   // We start by connecting to a WiFi network
//   Serial.println();
//   Serial.print("Connecting to ");
//   Serial.println(ssid);

//   WiFi.mode(WIFI_STA);
//   WiFi.begin(ssid, password);
//   //等待连接成功
//   while (WiFi.status() != WL_CONNECTED) {
//     delay(500);
//     Serial.print(".");
//   }

//   randomSeed(micros());
//   //连接wifi
//   Serial.println("");
//   Serial.println("WiFi connected");
//   Serial.println("IP address: ");
//   Serial.println(WiFi.localIP());
//   //连接mqtt服务器
//   client.setServer(mqtt_server, 1883);
//   client.setCallback(callback);
// }

// void callback(char* topic, byte* payload, unsigned int length) {
//   Serial.print("Message arrived [");
//   Serial.print(topic);
//   Serial.print("] ");
//   for (int i = 0; i < length; i++) {
//     Serial.print((char)payload[i]);
//   }
//   Serial.println();

//   // Switch on the LED if an 1 was received as first character
//   // if ((char)payload[0] == '1') {
//   //   digitalWrite(BUILTIN_LED, LOW);   // Turn the LED on (Note that LOW is the voltage level
//   //   // but actually the LED is on; this is because
//   //   // it is active low on the ESP-01)
//   // } else {
//   //   digitalWrite(BUILTIN_LED, HIGH);  // Turn the LED off by making the voltage HIGH
//   // }

// }
// void reconnect() 
// {
//   // Loop until we're reconnected
//   while (!client.connected())
//   {
//     Serial.print("Attempting MQTT connection...");
//     // Create a random client ID
//     String clientId = "ESP32Client-";//随机ID
//     clientId += String(random(0xffff), HEX);
//     // Attempt to connect
//     if (client.connect(clientId.c_str())) 
//     {
//       Serial.println("connected");
//       // Once connected, publish an announcement...
//       client.publish("outTopic", "hello world");//发布信息(主题名需要更改)
//       // ... and resubscribe
//       client.subscribe("inTopic");
//     } 
//     else
//     {
//       Serial.print("failed, rc=");
//       Serial.print(client.state());
//       Serial.println(" try again in 5 seconds");
//       // Wait 5 seconds before retrying
//       delay(5000);
//     }
//   }
// }

