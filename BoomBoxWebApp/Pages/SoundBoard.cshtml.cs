using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using MQTTnet;
using MQTTnet.Client;

namespace BoomBoxWebApp.Pages;

public class SoundBoardModel : PageModel
{
    private readonly ILogger<SoundBoardModel> _logger;

    public SoundBoardModel(ILogger<SoundBoardModel> logger)
    {
        _logger = logger;
    }

    public void OnGet()
    {
    }

    //OnPost() will run when submiting a form with method="post"
    public void OnPost()
    {
        //Getting values from the form
        var brokerIP = Request.Form["Host"];
        var port = Request.Form["Port"];
        var topic = Request.Form["Topic"];
        var payload = Request.Form["Message"];

        //Calling the publishing function
        _ = Publish_Message(brokerIP, port, topic, payload);
    }

    public static async Task Publish_Message(string brokerIP, string port, string topic, string payload)
    {
        var mqttFactory = new MqttFactory();
        using (var mqttClient = mqttFactory.CreateMqttClient())
        {
            var mqttClientOptions = new MqttClientOptionsBuilder().WithWebSocketServer(brokerIP + ":9001/mqtt").Build();

            await mqttClient.ConnectAsync(mqttClientOptions, CancellationToken.None);

            var appMessage = new MqttApplicationMessageBuilder()
                .WithTopic(topic)
                .WithPayload(payload)
                .Build();

            await mqttClient.PublishAsync(appMessage, CancellationToken.None);
            await mqttClient.DisconnectAsync();
            Console.WriteLine("MQTT message published");
        }
    }
}

