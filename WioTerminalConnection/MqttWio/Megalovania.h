/*
  This is the conversion of the song "Megalovania" by Toby Fox into readable frequencies for the Wio Terminal.
  The notes are gotten from a conversion for Arduino (https://github.com/AnonymousAlly/Arduino-Music-Codes/blob/master/Megalovania.ino).

  This is mapped by someone without musical knowledge, so there could be some mistakes regarding music theory, naming etc.
  That being said, the format used is <octave>.<note>, following the guidelines setup in "Notes.h" (where you can also find more details).

  Some notes had to be adapted, as the documentation did not allow for B_SHARP, for example.
*/

#include "Notes.h"

Note Megalovania[] = {

  {A.D, one, one},
  {A.D, one, one},
  {T.D, double, double},
  {A.A, double, triple},
  {A.A_SHARP, one, double},
  {A.G, double, double},
  {A.F, double, double},
  {A.D, one, one},
  {A.F, one, one},
  {A.G, one, one},
  {A.C, one, half},
  {A.C, one, half},
  {A.C, one, half},
  {A.C, one, half},
  {T.D, double, double},
  {A.A, double, triple},
  {A.A_SHARP, one, double},
  {A.G, double, double},
  {A.F, double, double},
  {A.D, one, one},
  {A.F, one, one},
  {A.G, one, one},
  {B.B, one, one},
  {B.B, one, one},
  {T.D, double, double},
  {A.A, double, triple},
  {A.A_SHARP, one, double},
  {A.G, double, double},
  {A.F, double, double},
  {A.D, one, one},
  {A.F, one, one},
  {A.G, one, one},
  {A.C, half, half},
  {A.C, half, half},
  {A.C, half, half},
  {A.C, half, half},
  {T.D, double, double},
  {A.A, double, triple},
  {A.A_SHARP, one, double},
  {A.G, double, double},
  {A.F, double, double},
  {A.D, one, one},
  {A.F, one, one},
  {A.G, one, one},
  {A.A, double, triple},
  {A.A_SHARP, one, double},
  {A.G, double, double},
  {A.F, double, double},
  {A.D, one, one},
  {A.F, one, one},
  {A.G, one, one},
  {A.C, one, half},
  {A.C, one, half},
  {A.C, one, half},
  {A.C, one, half},
  {T.D, double, double},
  {A.A, double, triple},
  {A.A_SHARP, one, double},
  {A.G, double, double},
  {A.F, double, double},
  {A.D, one, one},
  {A.F, one, one},
  {A.G, one, one},
  {B.B, one, one},
  {B.B, one, one},
  {T.D, double, double},
  {A.A, double, triple},
  {A.A_SHARP, one, double},
  {A.G, double, double},
  {A.F, double, double},
  {A.D, one, one},
  {A.F, one, one},
  {A.G, one, one},
  {A.C, half, half},
  {A.C, half, half},
  {A.C, half, half},
  {A.C, half, half},
  {T.D, double, double}


  //line 172 - B3

};