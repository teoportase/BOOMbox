/*
  This code plays a given song through the Seeed speaker connected to a Wio Terminal. The implementation below is based on the 
  example code on https://wiki.seeedstudio.com/Grove-Speaker/#play-with-arduino.
*/

#include "Amogus.h"
#include "Megalovania.h"

#define SPEAKER 0
#define CurrentSong Amogus

const int SONG_LENGTH = sizeof(CurrentSong) / sizeof(Note);

void setup()
{
    pinSpeaker();

    for(int note_index=0;note_index<SONG_LENGTH;note_index++)
    {
        sound(note_index);
        delay(CurrentSong[note_index].delay);
    }
}
void loop()
{

}
void pinSpeaker()
{
    pinMode(SPEAKER,OUTPUT);
    digitalWrite(SPEAKER,LOW);
}

void sound(uint8_t note_index)
{
    for(int i=0;i<CurrentSong[note_index].duration;i++)
    {
        digitalWrite(SPEAKER,HIGH);
        delayMicroseconds(CurrentSong[note_index].frequency);
        digitalWrite(SPEAKER,LOW);
        delayMicroseconds(CurrentSong[note_index].frequency);
    }
}