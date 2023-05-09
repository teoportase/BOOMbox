namespace BoomBoxWeb.Tests
{
    public class Tests
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
    }
}