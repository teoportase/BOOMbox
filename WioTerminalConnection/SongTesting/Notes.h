/*
  This file is a useful implementation for easily writing notes for the Seeed Wio Terminal Speaker. The notes (using the letter system) have been mapped to their
  respective frequencies according to the documentation (https://files.seeedstudio.com/wiki/Grove-Speaker/res/Tone.pdf).

  The speaker is capable of 3 octaves: bass, alto, and treble (in ascending order of pitch). The structures below are named with the initial of the octave they represent.
  Usually, Bass corresponds to octave 3 on the piano, Alto to octave 4, and Treble to octave 5.

  There are some limitations. Some notes do not have a frequency in the chart linked above, so in practice, you could move up or down to the next octave
  (if possible), and use that note.
  
  There is also a pause and note durations (milliseconds) defined for breaks and tempo changes. The rest does make a small "flick" sound instead of total silence.
*/

#ifndef _NOTES_
#define _NOTES_

struct Note{
  int frequency;
  int duration;
  int delay;
};

#define REST 0
#define half 50
#define one 50
#define double 100
#define triple 200

struct Bass{
  int C;
  int C_SHARP;
  int D;
  int D_SHARP;
  int E;
  int F;
  int F_SHARP;
  int G;
  int G_SHARP;
  int A;
  int A_SHARP;
  int B;
};

Bass B = {1911, 1804, 1703, 1607, 1517, 1432, 1351, 1276, 1204, 1136, 1073, 1012};

struct Alto{
  int C;
  int C_SHARP;
  int D;
  int D_SHARP;
  int E;
  int F;
  int F_SHARP;
  int G;
  int G_SHARP;
  int A;
  int A_SHARP;
  int B;
};

Alto A = {956, 902, 851, 804, 758, 716, 676, 638, 602, 568, 536, 506};

struct Treble{
  int C;
  int C_SHARP;
  int D;
  int D_SHARP;
  int E;
  int F;
  int F_SHARP;
  int G;
  int G_SHARP;
  int A;
  int A_SHARP;
  int B;
};

Treble T = {478, 451, 426, 402, 379, 358, 338, 319, 301, 284, 268, 253};

#endif