namespace BoomBoxWeb.Tests
{
    using BoomBoxWeb.Utils;
    using Bunit;
    using System.Threading.Tasks;
    using Index = Pages.Index;

    public class Tests : TestContext
    {
        [Test]
        public void TestRenderIndex()
        {
            var indexComponent = RenderComponent<Index>();
            Assert.That(indexComponent, Is.Not.Null);
        }

        [Test]
        public async Task TestMqtt()
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