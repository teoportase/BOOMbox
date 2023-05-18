using Index = BoomBoxWeb.Pages.Index;

namespace BoomBoxWeb.Tests
{
    public class IndexPageTest : TestContext
    {
        [Test, Category("IndexPage")]
        public void IndexRenderTest()
        {
            var cut = RenderComponent<Index>();
            Assert.That(cut, Is.Not.Null);

            var boombox = cut.Find("#boombox-icon");

            boombox.MarkupMatches("<input type=\"image\" id=\"boombox-icon\" src=\"res/Boombox.svg\" alt=\"boombox icon\" />");
        }

        [Test, Category("IndexPage")]
        public void IndexRedirectTest()
        {
            var ctx = new TestContext();
            var nav = ctx.Services.GetRequiredService<NavigationManager>();

            var cut = ctx.RenderComponent<Index>();

            cut.Find("#boombox-icon").Click();

            Assert.That(nav.Uri.ToString(), Is.EqualTo("http://localhost/SoundBoard"));
        }

        [Test, Category("IndexPage")]
        public async Task IndexLocalStorageTest()
        {
            string valueSet = "Test value";
            var localStorage = this.AddBlazoredLocalStorage();

            await localStorage.SetItemAsync("testKey", valueSet);

            string valueGet = await localStorage.GetItemAsync<string>("testKey");

            Assert.That(valueSet, Is.EqualTo(valueGet));
        }
    }
}