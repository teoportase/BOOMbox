# BOOMbox

## Introduction

This is a mini-project for DIT113 Systems Development course with an emphasis on music. Do you listen to music on a daily basis? Are you tired of your big speakers? Do you want a small companion to react to the music? If your answer is **YES** to any of the previous questions, then today is your lucky day! Introducing to you project **BOOMbox**! A small, portable, and effortless device to listen to your favourite songs anywhere, anytime! This project is a creative idea from group 12 to make your daily lives better. **You're Welcome!**

## Purpose and Benefits

The goal of this project is to add a spark of joy to our daily lives while doing what we love to do most! **listening to music**

## Description

As mentioned previously, this project comes in the form of a classic boombox (a speaker-like container for the device is optional, but highly encouraged). Controlling the device happens through a web application we have created where you can select the songs you want played, like them, and see recommendations. On the speaker side, when the device is turned on, the screen displays a sleeping [Kirby](https://kirby.nintendo.com/) when there is no music playing, and one that is singing when the opposite is true.

The hardware for this project is a [Seeed Wio Terminal](https://wiki.seeedstudio.com/Wio-Terminal-Getting-Started/), a [Grove Speaker](https://wiki.seeedstudio.com/Grove-Speaker/), and a wire to connect the two. When running the program on the device, you will see some of the following things on the Wio screen:
- a "Connecting... Please wait" message,
- a "Connecting to WiFi" message,
- a "Connecting to broker" message,
- a sleeping Kirby,
- a simple animation of Kirby singing "La la la!".

The first message is a loading message as the connection process begins. The second and third usually for a split second and are in relation to the way the device communicates with our web application. The device connects to a specified WiFi network and an MQTT broker. It "listens" for any commands that come from the web application. When the sleeping Kirby appears on screen, you are ready to play songs! Kirby "sings" by animating his mouth to open and close, as well as add the "La la la!" text to help with the illusion of singing. The animation plays for every note of the song.

For more information about how to use the application, check out the user manual on the Wiki page.

TODO: *add more abt the frameworks and web app; add section abt other sensor we're adding; diagrams; python midi script; the CD deployment*

### Frameworks
- ASP.NET

### Hardware limitations
- The speaker mentioned is not powerful enough to play lyrics to songs, so the device will only play a basic melody for the selected song;
- The device has a bug where sometimes it disconnects from the broker, and it erases the queue of songs. The device will automatically reconnect, but the user will need to reselect which songs they want to play;
- For very fast-paced songs, the animation of Kirby singing may cause a very slight delay. We have tried to reduce it as much as possible, but there is a small chance it may still be noticeable for some songs;

## Setup guide

In order to run this project, you need to specify the WiFi network through which the device and web application will communicate. The necessary hardware is the Wio Terminal and accessories mentioned above, and the software is a text editing app that can create and edit C header files.

In the folder ```WioTerminalConnection > MqttWio``` create a C header file named ```ServerData.h```. Inside add the following text:

```txt
#define SSID "<WiFi name>"
#define PASSWORD "<WiFi password>"
#define MQTT_SERVER "18.116.40.41"
```

The text inside the ```< >``` brackets, including the brackets, should be replaced by the WiFi name and password your device that you are running the web application is connected to.

(To be added: *How users can get started with the project?*)

## Video Demo

TODO: *add link here*

## Contact Us

If you have any questions relating this project feel free to contact us [here]().

## Contributors

Group 12 consists of 6 beautiful young minds:
- **Arvin Rahimi** (<gusrahimar@student.gu.se>) - focused on the implementation of the various sensors connected to the boombox, including some that did not make the final version and the connection between the Wio Terminal and the web application;
- **Adrian Hassa** (<gushasade@student.gu.se>) - worked on the development of the backend of the web application;
- **David Boram Hong** (<guscholcda@student.gu.se>) - focused on the frontend of the application, including adding the dark theme - light theme feature;
- **Ionel Pop** (<guspopio@student.gu.se>) - aided in the development of the backend of the web application, as well as creating on CI/CD for the project and the script for converting ```midi``` files to readable text by the device;
- **Marko Mojsov** (<gusmojsma@student.gu.se>) - focused on the frontend of the web application and its design;
- **Teodora Portase** (<gusportte@student.gu.se>) - worked on a way for the speaker to play the necessary notes by creating a class that has notes and their octave to the respective frequency, as well as implementing the Kirby singing and sleeping.

TODO: *add everyone's major contributions to the project here*
