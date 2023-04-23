using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;

namespace BoomBoxWebApp.Pages;

public class SoundBoardModel : PageModel
{
    private readonly ILogger<SoundBoardModel> _logger;

    public SoundBoardModel(ILogger<SoundBoardModel> logger)
    {
        _logger = logger;
    }

    public void OnGet()
    {
    }
}

