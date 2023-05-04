namespace BoomBoxWeb.Songs
{
    public class Song
    {
        public string title { get; set; }
        public string artist { get; set; }
        public string image { get; set; }

        public Song(string title, string artist, string image)
        {
            this.title = title;
            this.artist = artist;
            this.image = image;
        }
    }
}
