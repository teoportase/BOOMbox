using Microsoft.AspNetCore.Components.Web;
using Microsoft.AspNetCore.Components.WebAssembly.Hosting;
using BoomBoxWeb;

var builder = WebAssemblyHostBuilder.CreateDefault(args);

//If you're using Visual Studio and get an "error" in the line below,
//just ignore it, the app runs fine, it's just VS being stupid.
//Most likely it's a bug with .NET profiling, but it doesn't affect the app in any way
builder.RootComponents.Add<App>("#app");
builder.RootComponents.Add<HeadOutlet>("head::after");

builder.Services.AddScoped(sp => new HttpClient { BaseAddress = new Uri(builder.HostEnvironment.BaseAddress) });
await builder.Build().RunAsync();
