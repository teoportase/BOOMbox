namespace BoomBoxWeb.Songs
{
    public class Song
    {
        public string Title { get; set; }
        public string Artist { get; set; }
        public string Image { get; set; }

        public Song(string title, string artist, string image)
        {
            Title = title;
            Artist = artist;
            Image = image;
        }
    }
}
