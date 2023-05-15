#include "SpeakerNotes.h"

Note BadRomance[] = {
{478,198,0},
{426,198,1},
{380,198,1},
{478,198,0},
{358,596,0},
{380,198,0},
{358,198,0},
{380,198,1},
{426,397,0},
{426,397,199},
{507,198,0},
{478,397,0},
{426,198,199},
{380,529,0},
{380,99,166},
{380,198,0},
{426,298,100},
{478,198,0},
{478,298,496},
{478,198,0},
{426,198,1},
{380,198,1},
{478,198,0},
{358,596,0},
{380,198,0},
{358,198,0},
{380,198,1},
{426,397,0},
{426,397,199},
{507,198,0},
{478,397,0},
{426,198,199},
{380,529,0},
{380,99,166},
{380,198,0},
{426,298,100},
{478,198,0},
{478,298,1290},
{569,132,265},
{569,298,99},
{380,99,99},
{380,99,100},
{358,198,1},
{380,198,198},
{569,99,100},
{569,298,99},
{380,99,99},
{380,99,100},
{358,198,1},
{380,198,0},
{569,132,265},
{569,298,99},
{380,99,99},
{380,99,100},
{358,198,1},
{380,198,198},
{478,99,100}
// {478,198,1},
// {569,198,0},
// {478,265,132},
// {478,397,0},
// {569,132,265},
// {569,298,99},
// {380,99,99},
// {380,99,100},
// {358,198,1},
// {380,198,198},
// {569,99,100},
// {569,298,99},
// {380,99,99},
// {380,99,100},
// {358,198,1},
// {380,198,0},
// {569,132,265},
// {569,298,99},
// {380,99,99},
// {380,99,100},
// {358,198,1},
// {380,198,198},
// {478,99,100},
// {478,198,1},
// {569,198,0},
// {478,265,132},
// {478,397,198},
// {638,99,100},
// {569,198,1},
// {638,99,99},
// {569,198,0},
// {569,298,100},
// {569,99,99},
// {478,198,0},
// {569,99,100},
// {638,99,100},
// {569,198,0},
// {638,596,396},
// {569,99,100},
// {569,198,1},
// {638,99,99},
// {569,198,0},
// {638,99,100},
// {569,198,1},
// {638,99,99},
// {478,99,99},
// {569,99,100},
// {638,198,1},
// {569,397,0},
// {759,99,100},
// {638,198,1},
// {569,99,99},
// {569,992,596},
// {380,265,132},
// {478,265,132},
// {569,198,0},
// {759,99,100},
// {638,198,1},
// {569,198,0},
// {569,992,2382},
// {478,99,100},
// {478,198,1},
// {569,99,99},
// {478,198,0},
// {478,298,100},
// {569,99,99},
// {478,198,0},
// {478,99,100},
// {569,99,100},
// {478,397,793},
// {478,99,100},
// {478,198,1},
// {569,99,99},
// {478,198,0},
// {569,99,100},
// {478,198,1},
// {569,99,99},
// {478,99,99},
// {569,99,100},
// {569,198,1},
// {569,198,0},
// {638,198,0},
// {759,99,100},
// {638,198,1},
// {569,99,99},
// {569,992,596},
// {380,265,132},
// {478,265,132},
// {569,198,0},
// {759,99,100},
// {638,198,1},
// {569,198,0},
// {569,992,2482},
// {638,99,0},
// {638,99,0},
// {638,99,1},
// {638,99,0},
// {716,99,132},
// {759,132,728},
// {638,99,1},
// {638,99,0},
// {638,99,0},
// {638,99,1},
// {638,99,0},
// {716,99,132},
// {759,132,728},
// {569,99,100},
// {569,198,1},
// {638,99,99},
// {569,298,298},
// {638,99,99},
// {569,298,99},
// {638,265,0},
// {1137,397,727},
// {285,99,100},
// {285,198,1},
// {285,99,99},
// {285,198,0},
// {285,298,100},
// {319,99,99},
// {319,99,99},
// {319,99,100},
// {319,198,1},
// {426,265,131},
// {426,298,100},
// {380,198,0},
// {380,99,99},
// {380,99,100},
// {380,198,1},
// {380,99,99},
// {319,298,99},
// {426,198,199},
// {478,695,1091},
// {285,99,100},
// {285,198,1},
// {285,99,99},
// {285,198,0},
// {285,198,1},
// {285,198,1},
// {319,99,99},
// {319,99,99},
// {319,99,100},
// {319,198,1},
// {426,265,131},
// {426,298,100},
// {380,198,0},
// {380,99,99},
// {380,99,100},
// {380,198,1},
// {380,99,99},
// {301,298,99},
// {426,198,199},
// {478,695,99},
// {478,198,0},
// {426,198,1},
// {380,198,1},
// {478,198,0},
// {358,596,0},
// {380,198,0},
// {358,198,0},
// {380,198,1},
// {426,397,0},
// {426,397,199},
// {507,198,0},
// {478,397,0},
// {426,198,199},
// {380,529,0},
// {380,99,166},
// {380,198,0},
// {426,298,100},
// {478,198,0},
// {478,298,496},
// {478,198,0},
// {426,198,1},
// {380,198,1},
// {478,198,0},
// {358,596,0},
// {380,198,0},
// {358,198,0},
// {380,198,1},
// {426,397,0},
// {426,397,199},
// {507,198,0},
// {478,397,0},
// {426,198,199},
// {380,529,0},
// {380,99,166},
// {380,198,0},
// {426,298,100},
// {478,198,0},
// {478,298,1290},
// {569,132,265},
// {569,298,99},
// {380,99,99},
// {380,99,100},
// {358,198,1},
// {380,198,198},
// {569,99,100},
// {569,298,99},
// {380,99,99},
// {380,99,100},
// {358,198,1},
// {380,198,0},
// {569,132,265},
// {569,298,99},
// {380,99,99},
// {380,99,100},
// {358,198,1},
// {380,198,198},
// {478,99,100},
// {478,198,1},
// {569,198,0},
// {478,265,132},
// {478,397,198},
// {638,99,100},
// {569,198,1},
// {638,99,99},
// {569,198,0},
// {569,298,100},
// {569,99,99},
// {478,198,0},
// {569,99,100},
// {638,99,100},
// {569,198,0},
// {638,596,396},
// {569,99,100},
// {569,198,1},
// {638,99,99},
// {569,198,0},
// {638,99,100},
// {569,198,1},
// {638,99,99},
// {478,99,99},
// {569,99,100},
// {638,198,1},
// {569,397,0},
// {759,99,100},
// {638,198,1},
// {569,99,99},
// {569,992,596},
// {380,265,132},
// {478,265,132},
// {569,198,0},
// {759,99,100},
// {638,198,1},
// {569,198,0},
// {569,992,2382},
// {478,99,100},
// {478,198,1},
// {569,99,99},
// {478,198,0},
// {478,298,100},
// {569,99,99},
// {478,198,0},
// {478,99,100},
// {569,99,100},
// {478,397,793},
// {478,99,100},
// {478,198,1},
// {569,99,99},
// {478,198,0},
// {569,99,100},
// {478,198,1},
// {569,99,99},
// {478,99,99},
// {569,99,100},
// {569,198,1},
// {569,198,0},
// {638,198,0},
// {759,99,100},
// {638,198,1},
// {569,99,99},
// {569,992,596},
// {380,265,132},
// {478,265,132},
// {569,198,0},
// {759,99,100},
// {638,198,1},
// {569,198,0},
// {569,992,2482},
// {638,99,0},
// {638,99,0},
// {638,99,1},
// {638,99,0},
// {716,99,132},
// {759,132,728},
// {638,99,1},
// {638,99,0},
// {638,99,0},
// {638,99,1},
// {638,99,0},
// {716,99,132},
// {759,132,728},
// {569,99,100},
// {569,198,1},
// {638,99,99},
// {569,298,298},
// {638,99,99},
// {569,298,99},
// {638,265,0},
// {1137,397,727},
// {285,99,100},
// {285,198,1},
// {285,99,99},
// {285,198,0},
// {285,298,100},
// {319,99,99},
// {319,99,99},
// {319,99,100},
// {319,198,1},
// {426,265,131},
// {426,298,100},
// {380,198,0},
// {380,99,99},
// {380,99,100},
// {380,198,1},
// {380,99,99},
// {319,298,99},
// {426,198,199},
// {478,695,1091},
// {285,99,100},
// {285,198,1},
// {285,99,99},
// {285,198,0},
// {285,198,1},
// {285,198,1},
// {319,99,99},
// {319,99,99},
// {319,99,100},
// {319,198,1},
// {426,265,131},
// {426,298,100},
// {380,198,0},
// {380,99,99},
// {380,99,100},
// {380,198,1},
// {380,99,99},
// {301,298,99},
// {426,198,199},
// {478,695,99},
// {478,198,0},
// {426,198,1},
// {380,198,1},
// {478,198,0},
// {358,596,0},
// {380,198,0},
// {358,198,0},
// {380,198,1},
// {426,397,0},
// {426,397,199},
// {507,198,0},
// {478,397,0},
// {426,198,199},
// {380,529,0},
// {380,99,166},
// {380,198,0},
// {426,298,100},
// {478,198,0},
// {478,298,496},
// {478,198,0},
// {426,198,1},
// {380,198,1},
// {478,198,0},
// {358,596,0},
// {380,198,0},
// {358,198,0},
// {380,198,1},
// {426,397,0},
// {426,397,199},
// {507,198,0},
// {478,397,0},
// {426,198,199},
// {380,529,0},
// {380,99,166},
// {380,198,0},
// {426,298,100},
// {478,198,0},
// {478,298,1290},
// {569,132,265},
// {569,298,99},
// {380,99,99},
// {380,99,100},
// {358,198,1},
// {380,198,198},
// {569,99,100},
// {569,298,99},
// {380,99,99},
// {380,99,100},
// {358,198,1},
// {380,198,0},
// {569,132,265},
// {569,298,99},
// {380,99,99},
// {380,99,100},
// {358,198,1},
// {380,198,198},
// {478,99,100},
// {478,198,1},
// {569,198,0},
// {478,265,132},
// {478,397,0},
// {569,132,265},
// {569,298,99},
// {380,99,99},
// {380,99,100},
// {358,198,1},
// {380,198,198},
// {569,99,100},
// {569,298,99},
// {380,99,99},
// {380,99,100},
// {358,198,1},
// {380,198,0},
// {569,132,265},
// {569,298,99},
// {380,99,99},
// {380,99,100},
// {358,198,1},
// {380,198,198},
// {478,99,100},
// {478,198,1},
// {569,198,0},
// {478,265,132},
// {478,397,0},
// {638,298,99},
// {638,298,99},
// {638,99,99},
// {638,99,100},
// {638,198,1},
// {638,99,99},
// {638,198,0},
// {638,99,100},
// {638,99,100},
// {638,99,99},
// {638,99,99},
// {638,99,1},
// {638,298,0},
// {638,99,99},
// {638,298,99},
// {638,298,99},
// {638,99,99},
// {638,99,100},
// {638,198,1},
// {638,99,99},
// {638,99,99},
// {638,99,100},
// {638,99,100},
// {638,99,99},
// {638,99,99},
// {638,99,1},
// {638,298,0},
// {638,99,99},
// {638,298,99},
// {638,298,99},
// {638,99,99},
// {638,99,100},
// {638,198,1},
// {638,99,99},
// {638,198,0},
// {638,99,100},
// {638,99,100},
// {638,99,99},
// {638,99,99},
// {638,99,1},
// {638,298,0},
// {638,99,99},
// {638,298,99},
// {638,298,99},
// {638,99,99},
// {638,99,100},
// {638,198,1},
// {638,99,99},
// {638,99,99},
// {638,99,100},
// {638,99,0},
// {638,99,100},
// {638,99,132},
// {638,265,199},
// {638,198,0},
// {716,198,199},
// {478,198,1},
// {507,265,131},
// {638,265,133},
// {569,198,0},
// {569,397,0},
// {478,99,100},
// {478,198,0},
// {507,99,99},
// {507,198,1},
// {638,198,1},
// {759,198,0},
// {759,298,99},
// {478,198,1},
// {507,265,131},
// {638,198,200},
// {569,198,0},
// {569,198,199},
// {380,99,100},
// {380,99,99},
// {380,99,99},
// {380,198,1},
// {426,198,1},
// {478,198,0},
// {478,66,331},
// {478,198,1},
// {507,265,131},
// {638,265,133},
// {569,198,0},
// {569,397,0},
// {478,99,100},
// {478,198,0},
// {507,99,99},
// {507,198,1},
// {638,198,1},
// {759,198,0},
// {759,298,99},
// {478,198,1},
// {507,265,131},
// {638,198,200},
// {569,198,0},
// {569,198,199},
// {380,99,100},
// {380,99,99},
// {380,99,99},
// {380,198,1},
// {426,198,1},
// {478,198,0},
// {478,1390,595},
// {380,198,1},
// {380,99,99},
// {380,99,99},
// {380,198,1},
// {319,198,1},
// {478,198,0},
// {478,893,1886},
// {254,198,1},
// {285,198,0},
// {285,198,0},
// {319,99,0},
// {358,992,860},
// {285,99,298},
// {285,198,2581},
// {285,99,298},
// {285,198,662},
// {285,99,100},
// {285,198,1},
// {285,99,99},
// {285,198,0},
// {285,298,100},
// {319,99,99},
// {319,99,99},
// {319,99,100},
// {319,198,1},
// {426,265,131},
// {426,298,100},
// {380,198,0},
// {380,99,99},
// {380,99,100},
// {380,198,1},
// {380,99,99},
// {319,298,99},
// {426,198,199},
// {478,695,1091},
// {285,99,100},
// {285,198,1},
// {285,99,99},
// {285,198,0},
// {285,198,1},
// {285,198,1},
// {319,99,99},
// {319,99,99},
// {319,99,100},
// {319,198,1},
// {426,265,131},
// {426,298,100},
// {380,198,0},
// {380,99,99},
// {380,99,100},
// {380,198,1},
// {380,99,99},
// {301,298,99},
// {426,198,199},
// {478,695,3010},
// {285,99,298},
// {285,198,2581},
// {285,99,298},
// {285,198,2581},
// {285,99,298},
// {285,198,3640},
// {569,132,265},
// {569,298,99},
// {380,99,99},
// {380,99,100},
// {358,198,1},
// {380,198,198},
// {569,99,100},
// {569,298,99},
// {380,99,99},
// {380,99,100},
// {358,198,1},
// {380,198,0},
// {569,132,265},
// {569,298,99},
// {380,99,99},
// {380,99,100},
// {358,198,1},
// {380,198,198},
// {478,99,100},
// {478,198,1},
// {569,198,0},
// {478,265,132},
// {478,397,0}
};