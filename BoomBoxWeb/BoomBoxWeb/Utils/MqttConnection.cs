using MQTTnet;
using MQTTnet.Client;
using MQTTnet.Extensions.ManagedClient;
using System.Text;

namespace BoomBoxWeb.Utils
{
    public class MqttConnection
    {
        //Set this to the IP of a MQTT broker, or localhost if running everything locally
        private readonly static string BrokerIP = "localhost";
        
        //Message that will be proccessed by the Subscribe() method
        //Value assigned here is the 'default' one, before receiving anything
        public static string Reply { get; set; } = "Awaiting response...";
        

        public static async Task Publish_Message(string topic, string payload)
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

        public static async Task Subscribe(string topic)
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
