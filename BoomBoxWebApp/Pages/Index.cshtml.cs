using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using MQTTnet;
using MQTTnet.Client;
using System.Text;

namespace BoomBoxWebApp.Pages;

public class IndexModel : PageModel
{
    private readonly static string brokerIP = "localhost";
    private readonly static string topic = "#";
    private static string reply = "Awaiting response...";
    private readonly ILogger<IndexModel> _logger;
    
    public IndexModel(ILogger<IndexModel> logger)
    {
        _logger = logger;
    }

    public void OnGet()
    {
        _ = Handle_Received_Application_Message();
    }

    public static async Task Handle_Received_Application_Message()
    {

        var mqttFactory = new MqttFactory();

        using (var mqttClient = mqttFactory.CreateMqttClient())
        {
            var mqttClientOptions = new MqttClientOptionsBuilder().WithWebSocketServer(brokerIP + ":9001/mqtt").Build();

            mqttClient.ApplicationMessageReceivedAsync += e =>
            {
                reply = Encoding.UTF8.GetString(e.ApplicationMessage.Payload);
                Console.WriteLine("Received application message: " + reply);
                return Task.CompletedTask;

            };

            await mqttClient.ConnectAsync(mqttClientOptions, CancellationToken.None);

            var mqttSubscribeOptions = mqttFactory.CreateSubscribeOptionsBuilder()
                .WithTopicFilter(
                    f =>
                    {
                        f.WithTopic(topic);
                    })
                .Build();

            await mqttClient.SubscribeAsync(mqttSubscribeOptions, CancellationToken.None);

            Console.WriteLine("MQTT client subscribed to topic.");
            Console.ReadLine();
        }
    }

    public JsonResult OnGetReply() //TODO: rename it later so it's less general
    {
        return new JsonResult(reply);
    }
}
