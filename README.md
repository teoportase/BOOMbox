# BOOMbox

## Introduction

This is a mini-project for DIT113 Systems Development course with an emphasis on music. Do you listen to music on a daily basis? Are you tired of your big speakers? Is it a pain to not see the track information on your old soundbox? If your answer is **YES** to all the previous questions, then today is your lucky day! Introducing to you project **BOOMbox**! A small, portable, and effortless device to listen to your favourite playlists anywhere, anytime! This project is an innovative idea from group 12 to make your daily lives better. **You're Welcome!**

## Description

(To be added: *What the project does?*)

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

(To be added: *How users can get started with the project?*)

## Purpose

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
