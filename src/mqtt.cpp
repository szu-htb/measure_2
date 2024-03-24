#include "mqtt.h"

//WIFI
//const char* ssid = "444";    //需要更改WIFI名称      *后期需要修改通过smatconfig配网
//const char* password = "13712819852";  //需要更改WIFI密码
const char* mqtt_server = "broker.mqtt-dashboard.com";    //mqtt的broker网址（后期需要连接app的服务器）
WiFiClient espClient;//wifi对象
PubSubClient client(espClient);
unsigned long lastMsg = 0;
#define MSG_BUFFER_SIZE	(100)
char msg[MSG_BUFFER_SIZE];


void Wifi_Init()
{
  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  //等待连接成功
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  randomSeed(micros());
  //连接wifi
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  //连接mqtt服务器
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  // for (int i = 0; i < length; i++) {
  //   Serial.print((char)payload[i]);
  // }
  Serial.println();

  // Switch on the LED if an 1 was received as first character
  // if ((char)payload[0] == '1') {
  //   digitalWrite(BUILTIN_LED, LOW);   // Turn the LED on (Note that LOW is the voltage level
  //   // but actually the LED is on; this is because
  //   // it is active low on the ESP-01)
  // } else {
  //   digitalWrite(BUILTIN_LED, HIGH);  // Turn the LED off by making the voltage HIGH
  // }

}
void reconnect() 
{
  // Loop until we're reconnected
  while (!client.connected())
  {
    Serial.print("Attempting MQTT connection...");
    // Create a random client ID
    String clientId = "ESP32Client-";//随机ID
    clientId += String(random(0xffff), HEX);
    // Attempt to connect
    if (client.connect(clientId.c_str())) 
    {
      Serial.println("connected");
      // Once connected, publish an announcement...
      client.publish("outTopic", "hello world");//发布信息(主题名需要更改)
      // ... and resubscribe
      client.subscribe("inTopic");
    } 
    else
    {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}


/// @brief 发送给信息主题
void mqtt_Send()
{
  unsigned long now = millis();//两秒发布一次信息
  if (now - lastMsg > 2000) 
  {
    lastMsg = now;
    //snprintf (msg, MSG_BUFFER_SIZE, "hello world %ld", value);//需要发布的信息
    // Serial.print("Publish message: ");
    // Serial.println(msg);
    client.publish("topic", msg);//发布信息
  }
}