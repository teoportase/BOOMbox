namespace BoomBoxWeb.Songs
{
    public class Album
    {
        public string Name { get; set; }
        public List<Song> Songs { get; set; }

        public Album(string name)
        {
            this.Name = name;
            this.Songs = new List<Song>();
        }

        public void AddSong(Song song)
        {
            Songs.Add(song);
        }
    }
}
