using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using MQTTnet;
using MQTTnet.Client;


namespace BoomBoxWebApp.Pages;

public class SoundBoardModel : PageModel
{
    private readonly ILogger<SoundBoardModel> _logger;

    private string brokerIP = "localhost";
    private string port = "1883";
    private string topic = "sound";
    public Album Album { get; set; }

    public SoundBoardModel(ILogger<SoundBoardModel> logger)
    {
        _logger = logger;
    }

    public void OnGet(){
        Album = new Album("test");
        Song song1 = new("Rain On Me", "Lady Gaga", "gaga.png");
        Album.addSong(song1);
        Song song2 = new("Hyperballad", "Bjork", "riddle.png");
        Album.addSong(song2);
        Song song3 = new("Firework", "Katy Perry", "katy.png");
        Album.addSong(song3);
    }

    //OnPost() will run when submiting a form with method="post"
    public void OnPost()
    {
        //Getting values from the post method (it's a placeholder for now)
        string payload = "test message";

        //Calling the publishing function
        _ = Publish_Message(brokerIP, port, topic, payload);
    }


    public static async Task Publish_Message(string brokerIP, string port, string topic, string payload)
    {
        var mqttFactory = new MqttFactory();
        using (var mqttClient = mqttFactory.CreateMqttClient())
        {
            //Building ClientOptions
            var mqttClientOptions = new MqttClientOptionsBuilder().WithTcpServer(brokerIP).Build();

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

            Console.WriteLine("MQTT message published at " + brokerIP + ":" + port);
        }
    }
}

