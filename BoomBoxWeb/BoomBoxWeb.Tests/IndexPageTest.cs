using SoundBoard = BoomBoxWeb.Pages.SoundBoard;
using Blazored.LocalStorage;

namespace BoomBoxWeb.Tests
{
    public class IndexPageTest : TestContext
    {
        [Test, Category("IndexPage")]
        public void IndexRenderTest()
        {
            Services.AddBlazoredLocalStorage();
            var mock = Services.AddMockHttpClient();
            JSInterop.Setup<bool>("localStorage.hasOwnProperty", _ => true);

            var cut = RenderComponent<SoundBoard>();
            Assert.That(cut, Is.Not.Null);

            var boombox = cut.Find("#test");

            boombox.MarkupMatches("<input type=\"checkbox\" id=\"checkbox\" @bind=\"themeSwitch\" @oninput=\"ChangeTheme\" />");
        }

        [Test, Category("IndexPage")]
        public void IndexRedirectTest()
        {
            Services.AddBlazoredLocalStorage();
            var mock = Services.AddMockHttpClient();
            JSInterop.Setup<bool>("localStorage.hasOwnProperty", _ => true);

            var ctx = new TestContext();
            var nav = ctx.Services.GetRequiredService<NavigationManager>();
            var localStorage = this.AddBlazoredLocalStorage();

            var cut = ctx.RenderComponent<SoundBoard>();

            cut.Find("#nav").Click();
            cut.Find("#about--us").Click();

            Assert.That(nav.Uri.ToString(), Is.EqualTo("http://localhost/AboutUs"));
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