/*
  Some of the following code used for connecting to a WiFi network is taken from the WiFi page
  on the SeeedStudio webpage (https://wiki.seeedstudio.com/Wio-Terminal-Wi-Fi), under the "Connecting to Specified Network Example Code" section.

  Includes a way to play "Megalovania" if the message is "megalovania" and the song in "Amogus.h" if the message is "amogus". It is case sensitive.
  To check if the device connects properly to both WiFi and broker, open the Serial Monitor.
*/

// Libraries:
#include "rpcWiFi.h"              // for WiFi connection
#include "PubSubClient.h"         // for MQTT protocol
#include "TFT_eSPI.h"             // for Wio LCD display

// File with server information. Has defined: SSID, PASSWORD, MQTT_SERVER (IP/URL)
#include "ServerData.h"

// Song files:
#include "Amogus.h"
#include "Megalovania.h"

// Pin definitions
#define SPEAKER 0

// Wio Terminal LCD Display is 320 px wide (X), and 240 px tall (Y)
#define SCREEN_ORIENTATION 3          // (0,0) is in the top left corner
#define SCREEN_BACKGROUND TFT_GREEN
#define TEXT_X 10
#define TEXT_Y 120
#define TEXT_SIZE 2
#define TEXT_COLOR TFT_BLACK

// If needed, change the default port and topics here:
const int MQTT_PORT = 1883;
const char* MUSIC_CONTROLS = "boombox/controls";
const char* MUSIC_SELECT = "boombox/songs";
const char* CONNECTION_TOPIC = "boombox/connect";

// Create a fully instantiated WiFi client
WiFiClient wioTerminal;
PubSubClient client(wioTerminal);

// Setup LCD screen
TFT_eSPI screen;

void setup() {
  Serial.begin(115200);

  screen.begin();
  setupScreen(SCREEN_ORIENTATION, SCREEN_BACKGROUND, TEXT_COLOR, TEXT_SIZE);
  setupSpeaker();

  connectWiFi();
  connectBroker();
}

void loop() {
  if(WiFi.status() != WL_CONNECTED || !client.connected()) {
    printOnScreen("Connecting... Please wait", TEXT_X, TEXT_Y, TEXT_SIZE);
    connectWiFi();
    connectBroker();
  }

  client.loop();
}

// Gets called when a message is received from the subscribed topic
void callback(char* topic, byte* message, unsigned int length) {
  // Converting the topic to string if we want to print it
  String stringTopic(topic);
  Serial.println(stringTopic);
  
  Serial.print("Message [" + stringTopic + "]: ");
  String received_message = "";
  for (int i = 0; i < length; i++) {
    received_message += (char)message[i];
  }
  Serial.println(received_message);

  if(stringTopic.equals(MUSIC_SELECT)){
    playSong(received_message);
  }
}

// Prints the desired text on screen
// Parameters: the message, the x position of the text, the y position of the text, the size of the text (we recommend 1 to 3 so the text fits)
void printOnScreen(String message, int x, int y, int size) {
  screen.fillScreen(SCREEN_BACKGROUND);
  screen.setTextSize(size);
  screen.drawString(message, x, y);
}

// Song playing functions:
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

// Play desired song
void playSong(String songName) {
  if(songName.equalsIgnoreCase("amongus")) {
      int SONG_LENGTH = sizeof(Amogus) / sizeof(Note);

      for(int note_index=0;note_index<SONG_LENGTH;note_index++)
      {
        playNote(note_index, Amogus);
        delay(Amogus[note_index].delay);
      }
    }

    if(songName.equalsIgnoreCase("megalovania")) {
      int SONG_LENGTH = sizeof(Megalovania) / sizeof(Note);

      for(int note_index=0;note_index<SONG_LENGTH;note_index++)
      {
        playNote(note_index, Megalovania);
        delay(Megalovania[note_index].delay);
      }
    }
}

// Connectivity functions:
// Connects device to the WiFi network specified
void connectWiFi() {
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();

  Serial.println("Connecting to WiFi..");
  WiFi.begin(SSID, PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
    WiFi.begin(SSID, PASSWORD);
  }
  Serial.println("Connected to the WiFi network!");
  printOnScreen("Connected to WiFi!", TEXT_X, TEXT_Y, TEXT_SIZE);
}

// Connects/reconnects the device to the broker using MQTT
void connectBroker() {
  client.setServer(MQTT_SERVER, MQTT_PORT);
  client.setCallback(callback);

  while (!client.connected()) {
    Serial.print("Connecting to MQTT broker...");
    if (client.connect("Wio Terminal")) {
      Serial.println("connected");
      printOnScreen("Connected to broker!", TEXT_X, TEXT_Y, TEXT_SIZE);
    }
    else {
      Serial.print("failed, rc=");
      Serial.print(client.state());   // to see more about the reasons the connection failed, check: https://pubsubclient.knolleary.net/api#state
      Serial.println(" retrying in 5 seconds");
      delay(5000);
    }
  }

  client.subscribe(MUSIC_CONTROLS);
  client.subscribe(MUSIC_SELECT);
  client.publish(CONNECTION_TOPIC, "Device connected.");
}

// Setup functions:
// Sets up the speaker
void setupSpeaker() {
  pinMode(SPEAKER, OUTPUT);
  digitalWrite(SPEAKER, LOW);
}

// For more information about these methods, visit https://wiki.seeedstudio.com/Wio-Terminal-LCD-Basic.
void setupScreen(uint8_t orientation, uint32_t backgroundColor, uint32_t textColor, uint8_t textSize){
  screen.setRotation(orientation);
  screen.fillScreen(backgroundColor);
  screen.setTextColor(textColor);
  screen.setTextSize(textSize);
}
