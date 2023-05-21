using Blazored.LocalStorage;
using BoomBoxWeb.Team;
using AboutUs = BoomBoxWeb.Pages.AboutUs;

namespace BoomBoxWeb.Tests
{
    public class AboutUsPageTest : TestContext
    {
        [Test, Category("AboutUsPage")]
        public void AboutUsRenderTest()
        {
            var cut = RenderComponent<AboutUs>();
            Assert.That(cut, Is.Not.Null);

            var members = cut.FindComponents<MemberComponent>();

            var membersAmount = 6;

            Assert.That(membersAmount, Is.EqualTo(members.Count));
        }

        [Test, Category("AboutUsPage")]
        public void AboutUsRedirectTest()
        {
            var ctx = new TestContext();
            var nav = ctx.Services.GetRequiredService<NavigationManager>();

            var cut = RenderComponent<AboutUs>();
            Assert.That(cut, Is.Not.Null);

            cut.Find("button").Click();

            Assert.That(nav.Uri.ToString(), Is.EqualTo("http://localhost/"));
        }

        [Test, Category("AboutUsPage")]
        public async Task AboutUsLocalStorageTest()
        {
            string valueSet = "Test value";
            var localStorage = this.AddBlazoredLocalStorage();

            await localStorage.SetItemAsync("testKey", valueSet);

            string valueGet = await localStorage.GetItemAsync<string>("testKey");

            Assert.That(valueSet, Is.EqualTo(valueGet));
        }
    }
}