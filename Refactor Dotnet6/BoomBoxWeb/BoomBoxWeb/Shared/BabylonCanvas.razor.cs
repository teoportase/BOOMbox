using Microsoft.AspNetCore.Components;
using Microsoft.JSInterop;
using System.Diagnostics;
using System.Threading.Tasks;

namespace BoomBoxWeb.Shared
{
    public class BabylonCanvasBase : ComponentBase
    {
        [Inject] IJSRuntime JsRuntime { get; set; }

        protected async override Task OnAfterRenderAsync(bool firstRender)
        {
            await base.OnAfterRenderAsync(firstRender);

            if (firstRender)
            {
                await JsRuntime.InvokeVoidAsync("babylonInterop.initCanvas", "babylon-canvas");
            }
        }
    }
}