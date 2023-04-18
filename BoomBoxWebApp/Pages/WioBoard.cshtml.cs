using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;

namespace BoomBoxWebApp.Pages;

public class WioBoardModel : PageModel
{
    private readonly ILogger<WioBoardModel> _logger;

    public WioBoardModel(ILogger<WioBoardModel> logger)
    {
        _logger = logger;
    }

    public void OnGet()
    {
    }
}

