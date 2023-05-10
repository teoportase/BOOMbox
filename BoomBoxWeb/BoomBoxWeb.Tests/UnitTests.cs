namespace BoomBoxWeb.Tests
{
    using BoomBoxWeb.Utils;
    using Bunit;
    using System.Threading.Tasks;
    using Index = Pages.Index;

    public class Tests : TestContext
    {
        [SetUp]
        public void Setup()
        {
        }

        [Test]
        public void Test1()
        {
            int a = 1;
            int b = 2;
            int result = a + b;
            Assert.That(result, Is.EqualTo(3));
        }

        [Test]
        public void Test2()
        {
            int a = 32;
            int b = 32;
            Assert.That(b, Is.EqualTo(a));
        }

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