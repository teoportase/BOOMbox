using MQTTnet;
using MQTTnet.Client;

namespace BoomBoxWeb.Utils
{
    public class MqttConnection
    {
        private readonly static string BrokerIP = "localhost";
        private readonly static string Port = "1883";
        private readonly static string Topic = "sound";

        public static async Task Publish_Message(string payload)
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
                    .WithTopic(Topic)
                    .WithPayload(payload)
                    .Build();

                //Publishing the message
                await mqttClient.PublishAsync(appMessage, CancellationToken.None);

                //Disconnecting from the broker
                await mqttClient.DisconnectAsync();

                Console.WriteLine("MQTT message published at " + BrokerIP + ":" + Port);
            }
        }

        //public void OnGet()
        //{
        //    //Starts the async function on page load
        //    _ = Handle_Received_Application_Message();
        //}

        //public static async Task Handle_Received_Application_Message()
        //{

        //    var mqttFactory = new MqttFactory();

        //    using (var mqttClient = mqttFactory.CreateMqttClient())
        //    {
        //        //Connecting to the broker with TCP 
        //        var mqttClientOptions = new MqttClientOptionsBuilder().WithTcpServer(brokerIP).Build();

        //        mqttClient.ApplicationMessageReceivedAsync += e =>
        //        {
        //            //After recieving a response, gets text from it and saves it in reply
        //            reply = Encoding.UTF8.GetString(e.ApplicationMessage.Payload);
        //            Console.WriteLine("Received application message: " + reply);
        //            return Task.CompletedTask;

        //        };

        //        //Connecting to the broker using ClientOptions (TCP)
        //        await mqttClient.ConnectAsync(mqttClientOptions, CancellationToken.None);

        //        var mqttSubscribeOptions = mqttFactory.CreateSubscribeOptionsBuilder()
        //            .WithTopicFilter(
        //                f =>
        //                {
        //                    f.WithTopic(topic);
        //                })
        //            .Build();

        //        //Subscribing to a topic using SubsribeOptions
        //        await mqttClient.SubscribeAsync(mqttSubscribeOptions, CancellationToken.None);

        //        Console.WriteLine("MQTT client subscribed to topic.");
        //        Console.ReadLine();
        //    }
        //}

        //public JsonResult OnGetReply() //TODO: rename it later in the project so it's less general
        //{
        //    return new JsonResult(reply);
        //}
    }
}
