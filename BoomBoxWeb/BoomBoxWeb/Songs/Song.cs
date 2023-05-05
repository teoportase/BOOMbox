namespace BoomBoxWeb.Songs
{
    public class Song
    {
        public string Title { get; set; }
        public string Artist { get; set; }
        public string Image { get; set; }

        public Song(string title, string artist, string image)
        {
            this.Title = title;
            this.Artist = artist;
            this.Image = image;
        }
    }
}
