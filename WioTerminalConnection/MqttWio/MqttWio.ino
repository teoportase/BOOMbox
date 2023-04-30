// libraries for WiFi connections and MQTT protocol
#include "rpcWiFi.h"
#include <PubSubClient.h>
#include "ServerData.h"        // file with the server information

/*
Some of the following code used for connecting to a WiFi network is taken from the WiFi page
on the SeeedStudio webpage (https://wiki.seeedstudio.com/Wio-Terminal-Wi-Fi), under the "Connecting to Specified Network Example Code" section.
*/

// If needed, change the default port, topic, and client ID here:
const int MQTT_PORT = 1883;
const char* MQTT_TOPIC = "#";

typedef void (*Callback)(char*, byte*, unsigned int);

// Creates a fully instatiated client
WiFiClient wifiClient;
PubSubClient client(wifiClient);

// To see if the device connects to the WiFi, open the Serial Monitor here.

// Gets called when a message is received from the subscribed topic
void callback(char* topic, byte* message, unsigned int length) {
  Serial.print("Message received: ");
  String received_message = "";
  for (int i = 0; i < length; i++) {
    received_message += (char)message[i];
  }
  Serial.println(received_message);
}

void setup() {  
  // Starts the first connection
  Serial.begin(115200);
  while(!Serial); // Wait for Serial to be ready

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
      Serial.print(client.state());   // to see more about the reasons the connection failed, check: https://pubsubclient.knolleary.net/api#state
      Serial.println(" retrying in 5 seconds");
      delay(5000);
    }
  }

  // The device subscribes to the topic
  client.subscribe(MQTT_TOPIC);

  client.publish("test", "help me lord");
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
}
