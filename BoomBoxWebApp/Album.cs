﻿using System.Collections;

namespace BoomBoxWebApp
{
    public class Album
    {
        private string name { get; set; }
        public List<Song> songs { get; set; } 

        public Album(string name) { 
            this.name = name;
            this.songs = new List<Song>();
        }

        public void addSong(Song song)
        {
            songs.Add(song);
        }
    }
}
