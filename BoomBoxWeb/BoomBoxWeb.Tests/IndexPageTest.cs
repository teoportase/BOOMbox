using Index = BoomBoxWeb.Pages.Index;

namespace BoomBoxWeb.Tests
{
    public class IndexPageTest : TestContext
    {
        [Test]
        public void IndexRenderTest()
        {
            var cut = RenderComponent<Index>();
            Assert.That(cut, Is.Not.Null);

            var boombox = cut.Find("#boombox-icon");

            boombox.MarkupMatches("<input type=\"image\" id=\"boombox-icon\" src=\"res/Boombox.svg\" alt=\"boombox icon\" />");
        }

        [Test]
        public void IndexRedirectTest()
        {
            var ctx = new TestContext();
            var nav = ctx.Services.GetRequiredService<NavigationManager>();

            var cut = ctx.RenderComponent<Index>();

            cut.Find("#boombox-icon").Click();

            Assert.That(nav.Uri.ToString(), Is.EqualTo("http://localhost/SoundBoard"));
        }       
    }
}