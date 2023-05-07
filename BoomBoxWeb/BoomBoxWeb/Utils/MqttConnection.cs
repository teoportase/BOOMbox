﻿using BoomBoxWeb.Pages;
using Microsoft.AspNetCore.Components;
using MQTTnet;
using MQTTnet.Client;
using MQTTnet.Extensions.ManagedClient;
using System.Text;

namespace BoomBoxWeb.Utils
{
    public class MqttConnection
    {
        /*
         * TODO:
         * We should make this class a singleton
         */

        private static MqttConnection instance;

        //Set this to the IP of a MQTT broker, or localhost if running everything locally
        private readonly string BrokerIP = "localhost";
        
        //Message that will be proccessed by the Subscribe() method
        //Value assigned here is the 'default' one, before receiving anything
        public string Reply { get; set; } = "Awaiting response...";

        private MqttConnection() {
            // Empty private constructor to prevent instantiation
            // Initialization code should go here
        }

        public static MqttConnection GetInstance()
        {
            instance ??= new MqttConnection(); // Silly goofy operator haha

            return instance;
        }
        

        public async Task Publish_Message(string topic, string payload)
        {
            var mqttFactory = new MqttFactory();
            using (var mqttClient = mqttFactory.CreateMqttClient())
            {
                //Building ClientOptions
                var mqttClientOptions = new MqttClientOptionsBuilder().WithWebSocketServer(BrokerIP + ":9001/mqtt").Build();

                //Conecting to the broker using ClientOptions
                await mqttClient.ConnectAsync(mqttClientOptions, CancellationToken.None);

                //Building the message using arguments
                var appMessage = new MqttApplicationMessageBuilder()
                    .WithTopic(topic)
                    .WithPayload(payload)
                    .Build();

                //Publishing the message
                await mqttClient.PublishAsync(appMessage, CancellationToken.None);

                //Disconnecting from the broker
                await mqttClient.DisconnectAsync();

                Console.WriteLine("MQTT message " + topic + "/" + payload + " published at " + BrokerIP);
            }
        }

        public async Task Subscribe(string topic)
        {
            //Declaring connection options
            var options = new ManagedMqttClientOptionsBuilder()
                .WithAutoReconnectDelay(TimeSpan.FromSeconds(5))
                .WithClientOptions(new MqttClientOptionsBuilder()
                    .WithClientId("TestClient")
                    .WithWebSocketServer(BrokerIP + ":9001/mqtt")
                    .Build())
                .Build();

            //Creating a managed MQTT client using connection options
            var mqttClient = new MqttFactory().CreateManagedMqttClient();

            //Proccessing the received message
            mqttClient.ApplicationMessageReceivedAsync += e =>
            {
                Reply = Encoding.UTF8.GetString(e.ApplicationMessage.Payload);
                Console.WriteLine("Received application message: " + Reply);

                return Task.CompletedTask;
            };

            //Subsribing to a topic
            await mqttClient.SubscribeAsync(topic);

            //Conecting to the broker using ClientOptions
            await mqttClient.StartAsync(options);

        }
    }
}
