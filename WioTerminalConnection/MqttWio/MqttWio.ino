/*
Some of the following code used for connecting to a WiFi network is taken from the WiFi page
on the SeeedStudio webpage (https://wiki.seeedstudio.com/Wio-Terminal-Wi-Fi), under the "Connecting to Specified Network Example Code" section.
*/

// libraries for WiFi connections and MQTT protocol
#include "rpcWiFi.h"
#include <PubSubClient.h>
#include "ServerData.h"        // file with the server information
#include "TFT_eSPI.h"

// Song files
#include "Amogus.h"
#include "Megalovania.h"

// Pin definitions
#define SPEAKER 0

// If needed, change the default port and topic here:
const int MQTT_PORT = 1883;
const char* MQTT_TOPIC = "#";

// Creates a fully instatiated client
WiFiClient wifiClient;
PubSubClient client(wifiClient);

// Define lcd screen
TFT_eSPI tft;

// To see if the device connects to the WiFi, open the Serial Monitor here.

void setup() {  

  //LCD Setup
  tft.begin();
  tft.setRotation(3);
  tft.fillScreen(TFT_GREEN);
  tft.setTextColor(TFT_BLACK);
  tft.setTextSize(3); // If i delete this doesn't work for some reason

  // Starts the first connection
  Serial.begin(115200);

  pinSpeaker();

  Serial.println("Connecting to WiFi..");
  WiFi.begin(SSID, PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.println("Connecting to WiFi..");
      WiFi.begin(SSID, PASSWORD);
      printOnScreen("Connecting to WiFi", 10, 50, 3);

  }
  Serial.println("Connected to the WiFi network");

  client.setServer(MQTT_SERVER, MQTT_PORT);
  client.setCallback(callback);

  // Connect to MQTT broker
  while (!client.connected()) {
    Serial.print("Connecting to MQTT broker...");
    printOnScreen("Connecting to broker", 10, 50, 3);
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
  client.loop();
}

// Gets called when a message is received from the subscribed topic
void callback(char* topic, byte* message, unsigned int length) {
  Serial.print("Message received: ");
  String received_message = "";
  for (int i = 0; i < length; i++) {
    received_message += (char)message[i];
  }
  Serial.println(received_message);

  // Converting the topic to string if we want to print it
  String stringTopic(topic);
  Serial.println(stringTopic);

  printOnScreen(received_message, 10, 100, 4);

  if(stringTopic == "music") {
    Serial.println("Correct topic");

    if(received_message == "amogus") {
      int SONG_LENGTH = sizeof(Amogus) / sizeof(Note);

      for(int note_index=0;note_index<SONG_LENGTH;note_index++)
      {
        playNote(note_index, Amogus);
        delay(Amogus[note_index].delay);
      }
    }

    if(received_message == "megalovania") {
      int SONG_LENGTH = sizeof(Megalovania) / sizeof(Note);

      for(int note_index=0;note_index<SONG_LENGTH;note_index++)
      {
        playNote(note_index, Megalovania);
        delay(Megalovania[note_index].delay);
      }
    }
  }
}

// Sets up the speaker
void pinSpeaker() {
  pinMode(SPEAKER, OUTPUT);
  digitalWrite(SPEAKER, LOW);
}

// Plays one note
void playNote(uint8_t note_index, Note song[]) {
  for(int i=0;i<song[note_index].duration;i++)
  {
    digitalWrite(SPEAKER,HIGH);
    delayMicroseconds(song[note_index].frequency);
    digitalWrite(SPEAKER,LOW);
    delayMicroseconds(song[note_index].frequency);
  }
}

void printOnScreen(String message, int x, int y, int size) {
  tft.setTextSize(size);
  tft.fillScreen(TFT_RED);
  tft.drawString(message, x, y);
}
