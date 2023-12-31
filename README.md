# BOOMbox

## Introduction

This is a mini-project for DIT113 Systems Development course with an emphasis on music. Do you listen to music on a daily basis? Are you tired of your big speakers? Do you want a small companion to react to the music? If your answer is **YES** to any of the previous questions, then today is your lucky day! Introducing to you project **BOOMbox**! A small, portable, and effortless device to listen to your favourite songs anywhere, anytime! This project is a creative idea from group 12 to make your daily lives better. **You're Welcome!**

&nbsp;              <!-- This is the empty space character -->


## Description

As mentioned previously, this project comes in the form of a classic boombox (a speaker-like container for the device is optional, but highly encouraged). Controlling the device happens through a web application we have created where you can select the songs you want played, like them, and see recommendations. On the speaker side, when the device is turned on, the screen displays a sleeping [Kirby](https://kirby.nintendo.com/) when there is no music playing, and one that is singing when the opposite is true. An LED bar will light up and turn off as it gets closer to the end of the song.

Our system can be briefly described using this diagram:

![Diagram of the BOOMbox system illustrating the user application, broker, Wio Terminal, and accessories](/ReadmeImages/system-diagram.jpg)


**For more information about how to use the application, check out the [user manual](https://git.chalmers.se/courses/dit113/2023/group-12/boombox/-/wikis/User-Manual) on the Wiki.**

**For developers looking to start with our project, check out the [Getting Started](https://git.chalmers.se/courses/dit113/2023/group-12/boombox/-/wikis/Get-started-for-developers) page on the Wiki.**

### Technologies and frameworks
- Blazor WebAssembly
- Arduino IDE
- Seeeduino Wio Terminal
- an attachable battery for the Wio Terminal
- Grove Speaker
- Grove LED bar

**For more detailed information of the technology used such as documentation for them, check out [the respective section](https://git.chalmers.se/courses/dit113/2023/group-12/boombox/-/wikis/home#tech-stack) of the wiki.**

### Hardware limitations
- The speaker mentioned is not powerful enough to play lyrics to songs, so the device will only play a basic melody for the selected song;
- The device has a bug where sometimes it disconnects from the broker, and it erases the queue of songs. The device will automatically reconnect, but the user will need to reselect which songs they want to play;
- For very fast-paced songs, the animation of Kirby singing may cause a very slight delay. We have tried to reduce it as much as possible, but there is a small chance it may still be noticeable for some songs;
- Currently, the way we implemented the `playSong()` method in the `MqttWio.ino` file is by using a sequence of if-statements. We tried to solve this issue by assigning each song a unique ID number and store the songs in a dynamically generated array but sadly, due to memory issues, this kept causing different bugs. Therefore, we discarded the idea.

&nbsp;

## Purpose and Benefits

The main purpose of the system is to entertain individuals who enjoy listening to `8-bit retro style` sounds,
and love playing around with soundboards.

As a user, you will be able to rejoice in playing a song wirelessly from any device, liking your favorite tracks,
and seeing a cute Kirby react every time a song snippet is being played.

&nbsp;

## Setup guide

Besides the hardware mentioned in the **"Technologies and frameworks"** section and the Arduino IDE, you will also need two wires* to connect the two accessories to the Wio and a WiFi connection.

\* *There are two types of wires: [jumper type](https://www.seeedstudio.com/Grove-4-pin-Male-Jumper-to-Grove-4-pin-Conversion-Cable-5-PCs-per-Pack.html?queryID=8b2492180bba9d5ebee0d287da73b02f&objectID=1321&indexName=bazaar_retailer_products) and [buckled type](https://www.seeedstudio.com/Grove-Universal-4-Pin-20cm-Unbuckled-Cable-5-PCs-Pack-p-749.html?queryID=9c7878f0bee30d7e0794cd8819b9e075&objectID=1822&indexName=bazaar_retailer_products). The buckled cables require an [extra battery](https://www.seeedstudio.com/Wio-Terminal-Chassis-Battery-650mAh-p-4756.html?queryID=efb6faccaebf56fd6b9b2c02df2d36f6&objectID=4756&indexName=bazaar_retailer_products) to connect, while the jumper type are enough for just the Wio Terminal. However, we assume that if you are using the jumper cables, you know how to connect them properly.*

First, clone the repository if you have not already. The command for that is:
`git clone https://git.chalmers.se/courses/dit113/2023/group-12/boombox.git`

Open the file `WioTerminalConnection > MqttWio > MqttWio.ino` in Arduino IDE.

In the meantime, add the accessories to the Wio board as so: the battery to the back of the Wio Terminal, the speaker to the port under the 5-way switch and the LED bar to the top right port of the battery. If you are using the jumper cables, connect them as instructed. If the pin specification in "Pin definitions" section in `MqttWio.ino` do not match how you connected the extra sensor, you can change them there. Connect the board to your device, and turn it on.

Once the file opens and the Wio is turned on, you will need to setup your board and install some libraries. To setup the board, go to `File > Preferences > Additional board URLs`, and paste *https://files.seeedstudio.com/arduino/package_seeeduino_boards_index.json*. After, go to the `Select Board` dropdown menu at the top, and search `Seeeduino Wio Terminal`. Select that option and the port that the IDE suggests. When prompted, select the option `Install manually`.

**It is important that you select version `1.8.3`, and do not update it.** The new version creates issues with the library for WiFi connections. If you would like, for safety, remove the link mentioned previously from its spot in `Additional board URLs` to avoid the auto-update.

Install the following libraries by pressing the `Library Manager` tab and searching for: **"rpcWiFi" by hongtai.liu** (install with all dependencies), **"PubSubClient" by Nick O'Leary**, and **"Grove LED Bar" by Seeed Studio**.

Create a new C header file by pressing `Ctrl + Shift + N` and name it `ServerData.h`. Add the following text inside:

```txt
#define SSID "<WiFi name>"
#define PASSWORD "<WiFi password>"
#define MQTT_SERVER "18.116.40.41"
```

The text inside the `<>` brackets, including the brackets, should be replaced by the WiFi name and password your device that you are running the web application is connected to.

Once all of the above steps are done, upload the code to the Wio board by pressing the upload button in the Arduino IDE.

![Screenshot of the Arduino IDE and the upload button is in a yellow box](/ReadmeImages/setup-arduino-upload.png)

If a green screen with the text "Connecting...Please wait" or a sleeping Kirby appear, the Wio is good to go!


Afterwards, on [this page](https://git.chalmers.se/courses/dit113/2023/group-12/boombox/-/environments) of the repository, click on the `Open` button. It looks like this: 

![Screenshot of the Gitlab environments page where the open button is located.](/ReadmeImages/setup-deployment.png)

This will open the web application. For it to successfully connect to the broker, you need to enable insecure content in your browser. A guide on how to do that in different browsers is available [here](https://experienceleague.adobe.com/docs/target/using/experiences/vec/troubleshoot-composer/mixed-content.html?lang=en). We had to go with this solution, since we didn't have time nor resources to implement network security features.

Enjoy!

**If you wish to run the application locally or the deployment is not working, check the section regarding [Running the Web App](https://git.chalmers.se/courses/dit113/2023/group-12/boombox/-/wikis/Get-started-for-developers#running-the-web-app) in the "Getting Started" page on the Wiki.**

&nbsp;


## Video Demo

Find the final demo [here](https://youtu.be/8WeQ-5S3Ck8).

&nbsp;


## Contributors

Group 12 consists of 6 beautiful young minds:
- **Arvin Rahimi** (<gusrahimar@student.gu.se>) - focused on the implementation of the various sensors connected to the boombox, including some that did not make the final version and the connection between the Wio Terminal and the web application, and worked on the README skeleton;
- **Adrian Hassa** (<gushasade@student.gu.se>) - worked on the development of the backend of the web application, aided with the frontend and the midi file reading program;
- **David Boram Hong** (<guscholcda@student.gu.se>) - focused on adding features to the frontend of the web application, including a dark/light theme feature, a hamburger menu, and a pause-play feature which did not make the final version;
- **Ionel Pop** (<guspopio@student.gu.se>) - aided in the development of the backend of the web application, as well as creating on CI/CD for the project and the script for converting `.midi` files to readable text by the device;
- **Marko Mojsov** (<gusmojsma@student.gu.se>) - worked on creating the frontend of the web application, polishing added features, ensuring the design remained cohesive and the repository Wiki;
- **Teodora Portase** (<gusportte@student.gu.se>) - worked on a way for the speaker to play the necessary notes by creating a class that has notes and their octave to the respective frequency, as well as implementing the Kirby singing/sleeping and the README;

If you have any questions relating this project, feel free to contact us at our respective emails.