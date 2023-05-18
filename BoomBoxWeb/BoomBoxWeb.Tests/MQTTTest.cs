using BoomBoxWeb.Utils;

namespace BoomBoxWeb.Tests
{
    public class MQTTTest
    {
        [Test, Category("MQTT")]
        public async Task MQTTPublishTest()
        {
            /*
             * Test that Publish_Message works with the HiveMQ broker
             */

            var host = "broker.hivemq.com";
            var topic = "sound";
            var payload = "test mqtt";

            await MqttConnection.GetInstance().PublishMessage(host, topic, payload);
        }
    }
}
