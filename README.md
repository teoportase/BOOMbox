# BOOMbox

## Introduction

This is a mini-project for DIT113 Systems Development course with an emphasis on music. Do you listen to music on a daily basis? Are you tired of your big speakers? Do you want a small companion to react to the music? If your answer is **YES** to any of the previous questions, then today is your lucky day! Introducing to you project **BOOMbox**! A small, portable, and effortless device to listen to your favourite songs anywhere, anytime! This project is a creative idea from group 12 to make your daily lives better. **You're Welcome!**

## Description

As mentioned previously, this project comes in the form of a classic boombox (a speaker-like container for the device is optional, but highly encouraged). Controlling the device happens through a web application we have created where you can select the songs you want played, like them, and see recommendations. On the speaker side, when the device is turned on, the screen displays a sleeping [Kirby](https://kirby.nintendo.com/) when there is no music playing, and one that is singing when the opposite is true.

The hardware for this project is a [Seeed Wio Terminal](https://www.seeedstudio.com/Wio-Terminal-p-4509.html), a [Grove Speaker](https://www.seeedstudio.com/Grove-Speaker-p-1445.html), and a wire to connect the two. When running the program on the device, you will see some of the following things on the Wio screen:
- a "Connecting to WiFi" message,
- a "Connecting to broker" message,
- a sleeping Kirby,
- a simple animation of Kirby singing "La la la!".

The first two are in relation to the way the device communicates with our web application. The device connects to a specified WiFi network and an MQTT broker. It "listens" for any commands that come from the web application. When the sleeping Kirby appears on screen, you are ready to play songs! Kirby "sings" by animating his mouth to open and close, as well as add the "La la la!" text to help with the illusion of singing. The animation plays for every note of the song.

TODO: *add more abt the frameworks and web app; add section abt other sensor we're adding*

### Frameworks
- ASP.NET

### Hardware limitations
- The speaker mentioned is not powerful enough to play lyrics to songs, so the device will only play a basic melody for the selected song;
- The device sometimes disconnects from the broker, and it erases the queue of songs. The device will automatically reconnect, but the user will need to reselect which songs they want to play;
- For very fast-paced songs, the animation of Kirby singing may cause a very slight delay. We have tried to reduce it as much as possible, but there is a small chance it may still be noticeable for some songs;

## Setup guide

In order to run this project, the broker, the Wio Terminal, and the Web App should be in the same network.

Before starting the app, the `mosquitto.conf` file should be modified. The file can be found in the installation directory for mosquitto.

```txt
listener 1883 0.0.0.0
listener 9001
protocol websockets
allow_anonymous true
```

This will allow incoming connections under the same network but from different machines, and allow the use of websockets under port 9001.

This is important because the Web App uses websockets to use the MQTT protocol.

The next step is creating a header file with the server information in the `WioTerminalConnection` folder. After opening the `MqttWio` file in the ArduinoIDE, create a new tab using **Ctrl + Shift + N**. Name the file `ServerData.h`, and include the following information:
```arduino
#define SSID "<WiFi name>"
#define PASSWORD "<WiFi password>"
#define MQTT_SERVER "<Server IP>"
```
After that, make sure the line `#include "ServerData.h"` is near the top of the `MqttWio` file.

Other information that you may need to change in the `MqttWio` file is the port number, the topic name, and the pin the buzzer is connected to (the last one is only applicable if using the buzzer test).
//TODO: remove the buzzer test later

(To be added: *How users can get started with the project?*)

## Purpose and Benefits

The goal of this project is to add a spark of joy to our daily lives while doing what we love to do most! **listening to music**

## Contact Us

If you have any questions relating this project feel free to contact us [here]().

## Contributors

Group 12 consists of 6 beautiful young minds:
- **Arvin Rahimi** (<gusrahimar@student.gu.se>)
- **Adrian Hassa** (<gushasade@student.gu.se>)
- **David Boram Hong** (<guscholcda@student.gu.se>)
- **Ionel Pop** (<guspopio@student.gu.se>)
- **Marko Mojsov** (<gusmojsma@student.gu.se>)
- **Teodora Portase** (<gusportte@student.gu.se>)
