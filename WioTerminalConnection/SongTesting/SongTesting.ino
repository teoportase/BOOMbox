#include "Megalovania.h"

#define SPEAKER 0

void setup()
{
    pinInit();

    for(int note_index=0;note_index<sizeof(Megalovania);note_index++)
    {
        sound(note_index);
        delay(Megalovania[note_index].delay);
    }
}
void loop()
{

}
void pinInit()
{
    pinMode(SPEAKER,OUTPUT);
    digitalWrite(SPEAKER,LOW);
}

void sound(uint8_t note_index)
{
    for(int i=0;i<Megalovania[note_index].duration;i++)
    {
        digitalWrite(SPEAKER,HIGH);
        delayMicroseconds(Megalovania[note_index].frequency);
        digitalWrite(SPEAKER,LOW);
        delayMicroseconds(Megalovania[note_index].frequency);
    }
}