namespace BoomBoxWeb.Songs
{
    public class Library
    {
        public List<Album> Albums { get; set; }

        public Library()
        {
            Albums = new List<Album>();
        }

        public void AddAlbum(Album album)
        {
            this.Albums.Add(album);
        }
    }
}
