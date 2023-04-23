// libraries for WiFi connections and MQTT protocol
#include <rpcWiFi.h>
#include <PubSubClient.h>
#include "ServerData.h"

// Add details here:
const int MQTT_PORT = 1883;
const char* MQTT_TOPIC = "#";

// Add the pin for the buzzer here:
const int BUZZER_PIN = 0;
bool shouldBuzz = false;
const char* BUZZ_MSG = "buzz";

/*
Some of the following code is taken from the WiFi page on the SeeedStudio webpage (https://wiki.seeedstudio.com/Wio-Terminal-Wi-Fi),
under the "Connecting to Specified Network Example Code" section
*/

WiFiClient wifiClient;
PubSubClient client(wifiClient);

// To see if the device connects to the WiFi, open the Serial Monitor here.

void setup() {
    // Sets the pin for the buzzer and tests to make sure it's connected
    pinMode(BUZZER_PIN, OUTPUT);
    digitalWrite(BUZZER_PIN, HIGH);
    delay(1000);

    digitalWrite(BUZZER_PIN, LOW);
    delay(1000);

    // Starts the first connection
    Serial.begin(115200);
    while(!Serial); // Wait for Serial to be ready

    // Set WiFi to station mode and disconnect from an AP if it was previously connected
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();

    Serial.println("Connecting to WiFi..");
    WiFi.begin(SSID, PASSWORD);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.println("Connecting to WiFi..");
        WiFi.begin(SSID, PASSWORD);
    }
    Serial.println("Connected to the WiFi network");

    client.setServer(MQTT_SERVER, MQTT_PORT);
    client.setCallback(callback);

    // Connect to MQTT broker
    while (!client.connected()) {
      Serial.print("Connecting to MQTT broker...");
      if (client.connect("Wio Terminal")) {
        Serial.println("connected");
      } else {
        Serial.print("failed, rc=");
        Serial.print(client.state());
        Serial.println(" retrying in 5 seconds");
        delay(5000);
      }
    }

    // The device subscribes to the topic
    client.subscribe(MQTT_TOPIC);
}

void callback(char* topic, byte* message, unsigned int length) {
  Serial.print("Message received: ");
  String received_message = "";
  for (int i = 0; i < length; i++) {
    received_message += (char)message[i];
  }
  Serial.println(received_message);

  if(received_message == BUZZ_MSG){
    shouldBuzz = true;
  }
}

void loop() {
  // Reestablish the connection if the device disconnects
  if (!client.connected()) {
    Serial.print("Reconnecting to MQTT broker...");

    if (client.connect("Wio Terminal")) {
      Serial.println("connected");
      client.subscribe(MQTT_TOPIC);
    }
    else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" retrying in 5 seconds");
      delay(5000);
    }
  }

  // Checks if the recently received message is the one that causes a buzz
  if(shouldBuzz) {
      digitalWrite(BUZZER_PIN, HIGH);
      delay(1000);

      digitalWrite(BUZZER_PIN, LOW);
      delay(1000);
      
      shouldBuzz = false;
    }

  // Check for incoming messages
  client.loop();
}