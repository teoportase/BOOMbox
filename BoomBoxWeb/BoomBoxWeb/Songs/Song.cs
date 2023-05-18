namespace BoomBoxWeb.Songs
{
    public class Song
    {
        public string Id { get; set; } = String.Empty;
        public string Title { get; set; }
        public string Artist { get; set; }
        public string Image { get; set; }

        public Song(string title, string artist, string image)
        {
            Title = title;
            Artist = artist;
            Image = image;
        }

        public override bool Equals(object obj)
        {
            if (obj == null)
            {
                return false;
            }
            if (obj is not Song)
            {
                return false;
            }
            return (this.Id == ((Song)obj).Id);
        }

        public static Song Emtpy { get; } = new Song(String.Empty, String.Empty, String.Empty);
    }
}
