using Blazored.LocalStorage;
using AboutUs = BoomBoxWeb.Pages.AboutUs;
using BoomBoxWeb.Team;

namespace BoomBoxWeb.Tests
{
    public class IndexPageTest : TestContext
    {
        [Test, Category("IndexPage")]
        public void AboutUsRenderTest()
        {
            var cut = RenderComponent<AboutUs>();
            Assert.That(cut, Is.Not.Null);

            var members = cut.FindComponents<MemberComponent>();

            var membersAmount = 6;

            Assert.That(membersAmount, Is.EqualTo(members.Count));
        }

        [Test, Category("IndexPage")]
        public void AboutUsRedirectTest()
        {
            var ctx = new TestContext();
            var nav = ctx.Services.GetRequiredService<NavigationManager>();

            var cut = RenderComponent<AboutUs>();
            Assert.That(cut, Is.Not.Null);

            cut.Find("button").Click();

            Assert.That(nav.Uri.ToString(), Is.EqualTo("http://localhost/"));
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