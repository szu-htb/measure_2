#include "smartconfig.h"

void SmartConfig()
{ 
  // WiFi.mode(WIFI_AP_STA);
   WiFi.mode(WIFI_STA);
   Serial.println("\r\n wait for smartconfig....");
   WiFi.beginSmartConfig();
     while(1)
   {
    Serial.print(".");
    delay(500);
    if ( WiFi.smartConfigDone())
    {
      Serial.println("SmartConfig Success");
      Serial.printf("SSID:%s\r\n",WiFi.SSID().c_str());
      Serial.printf("PSW:%s\r\n",WiFi.psk().c_str());    
      break;      
    }
   } 
}
bool AutoConfig()
{
  WiFi.begin();
  for (int i=0; i<20; i++)
  {
    int wstatus = WiFi.status();
    if (wstatus == WL_CONNECTED )  
       {  esp_wifi_set_storage(WIFI_STORAGE_RAM);//自动保存wifi信息
          Serial.println("wifi smartConfig success");
          Serial.printf("SSID:%s",WiFi.SSID().c_str());
          Serial.printf(",PWS:%s\r\n",WiFi.psk().c_str());
          Serial.print("localIP:");
          Serial.println(WiFi.localIP());
          Serial.print(",GateIP:");
          Serial.println(WiFi.gatewayIP()); 
          WiFi.setAutoConnect(true);  // 设置自动连接        
          return true;
       }
       else
       {
          Serial.print("WIFI AutoConfig Waiting ....");
          Serial.println(wstatus);
          delay(1000);
       }   
  }
  Serial.println("Wifi autoconfig faild!");
  return false;
  }
  
// void setup() {
//   Serial.begin(115200);
//   if (!AutoConfig())
//   {
//    SmartConfig();
//   }  
//   esp_wifi_restore();  //删除保存的wifi信息
  
// }
 


// #include <WiFi.h>

// void SmartConfig()
// {
//   WiFi.mode(WIFI_STA);
//   Serial.println("\r\nWait for Smartconfig...");
//   WiFi.beginSmartConfig();
//   while (1)
//   {
//     Serial.print(".");
//     delay(500);                   // wait for a second
//     if (WiFi.smartConfigDone())
//     {
//       Serial.println("SmartConfig Success");
//       Serial.printf("SSID:%s\r\n", WiFi.SSID().c_str());
//       Serial.printf("PSW:%s\r\n", WiFi.psk().c_str());
//       break;
//     }
//   }
// }

// bool AutoConfig()
// {
//     WiFi.begin();
//     //如果觉得时间太长可改
//     for (int i = 0; i < 20; i++)
//     {
//         int wstatus = WiFi.status();
//         if (wstatus == WL_CONNECTED)
//         {
// 	        Serial.println("WIFI SmartConfig Success");
// 	        Serial.printf("SSID:%s", WiFi.SSID().c_str());
// 	        Serial.printf(", PSW:%s\r\n", WiFi.psk().c_str());
// 	        Serial.print("LocalIP:");
// 	        Serial.print(WiFi.localIP());
// 	        Serial.print(" ,GateIP:");
// 	        Serial.println(WiFi.gatewayIP());
// 	        return true;
//         }
//         else
//         {
// 	        Serial.print("WIFI AutoConfig Waiting......");
// 	        Serial.println(wstatus);
// 	        delay(1000);
//         }
//     }
//     Serial.println("WIFI AutoConfig Faild!" );
//     return false;
// }
