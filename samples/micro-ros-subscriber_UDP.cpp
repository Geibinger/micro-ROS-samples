#include <ros2arduino.h>
#include <WiFi.h>
#include <WiFiUdp.h>

#include "conf_network.h"

#ifndef LED_BUILTIN // To support some boards (eg. some esp32 boards)
#define LED_BUILTIN 13
#endif 

WiFiUDP XRCEDDS_PORT;

void subscribeLed(std_msgs::Bool* msg, void* arg)
{
  (void)(arg);

  digitalWrite(LED_BUILTIN, msg->data);
}

class LedSub : public ros2::Node
{
public:
  LedSub()
  : Node("ros2arduino_sub_node")
  {
    this->createSubscriber<std_msgs::Bool>("arduino_led", (ros2::CallbackFunc)subscribeLed, nullptr);
  }
};

void setup() 
{
  WiFi.begin(SSID, SSID_PW);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  XRCEDDS_PORT.begin(AGENT_PORT);
  
  ros2::init(&XRCEDDS_PORT);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() 
{
  static LedSub LedNode;

  ros2::spin(&LedNode);
}