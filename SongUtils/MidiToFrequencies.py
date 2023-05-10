'''
This python script converts midi files to frequencies that can be used with the `Grove Speaker`.
It also exports them in a csv file for future processing.
To use this library, you need Python 3.x installed along with the `music21` lirary.
You can install music21 by running pip install music21 in your selected environment
'''

import os
import math
from music21 import converter, note as note21, instrument as instrument21

'''
Converts the midi file into a txt file that has:
    - The desired frequency for the `Grove Speaker`
    - The duration of the note
    - The delay of the note
With the following format:
    {frequency_0,duration_0,delay_0},
    {frequency_1,duration_1,delay_1},
    ...
    {frequency_n,duration_n,delay_n}
Where frequency, duration, and delay are Integers
'''
def midi_to_txt(filename):

    try:
        midi = converter.parse(filename)
    except FileNotFoundError:
        print('File not found')

    notes = []
    notes_to_parse = None

    '''
    Since most midi files have piano parts,
    we get the melody from that instrument
    '''
    parts = instrument21.partitionByInstrument(midi)

    instrument_names = []

    try:
        for instrument in parts:
            name = (str(instrument).split(' ')[-1])[:-1]
            instrument_names.append(name)
    except TypeError:
        print('Type is not iterable')
        return None
    
    try:
        piano_index = instrument_names.index('Piano')
    except ValueError:
        print('%s does not have any Piano part' % filename)
        return None
    
    notes_to_parse = parts.parts[piano_index].recurse()

    for element in notes_to_parse:
        
        # We make sure that we only get the individual notes,
        # not the chords
        if isinstance(element, note21.Note):
            freq = str(noteToGroveFrequency(element.pitch.midi))
            if (freq == 'None'):
                continue
            duration = check_float(str(element.duration)[27:-1])
            delay = check_float(str(element.offset)) # Need to fix this to get the distance between notes
            notes.append([freq, duration, delay])
    
    baseFilename = os.path.splitext(filename)[0]
    outputFilename = f"{baseFilename}_new.txt"

    with open(outputFilename, "w") as f:
        for n in notes:
            f.write(f"\u007b{n[0]},{n[1]},{n[2]}\u007d,\n")

'''
It is important to note that this function doesn't convert the midi notes to frequencies
but to the type of data that the `Grove Speaker` requires.
The formula to convert midi notes to frequencies was taken from this site:
https://gist.github.com/YuxiUx/ef84328d95b10d0fcbf537de77b936cd

To convert from frequencies to wioFrequencies we first calculate the reciprocal of
the frequency (1/freq), and then we multiply by 1_000_000 to get the value in [μs].
We finally divide by 4 to compensate for the octaves of the `Grove Speaker`

Note:
    The frequencies for the grove spekare are actually the reciprocal of frequency.
    This means that insted of getting "the number of waves per second", we get
    "how long does it take for one wave to pass".
'''
def noteToGroveFrequency(note):

    #frequency of A (coomon value is 440Hz)
    a = 440

    freq = (a / 32) * (2 ** ((note - 9) / 12))
    groveFreq = math.ceil((1 / freq) * (1_000_000) / 4)

    '''
    The maximum and minimum values that the Grove Speaker accepts are:
        1911 and 253.
    Therefore, if the value is out of bounds, we return None and we
    don't append that note to the file
    '''
    if (groveFreq > 1911 or groveFreq < 253):
        return None
    
    return (groveFreq)

'''
This function fixes the issue which comes from some note's duration.
    For example, some notes has a duration of 14/3 or 7/3.

Both duration and offset are measured in quarter notes. We decided to
multiply by 200 since this gives us a good timing in general
'''
def check_float(duration):
    if('/' in duration):
        numerator = float(duration.split('/')[0])
        denominator = float(duration.split('/')[1])
        duration = float(numerator/denominator)
    
    durationInMilliseconds = 1
    durationInMilliseconds = float(duration) * 200
    return round(durationInMilliseconds)

file = input("Enter the path of the file: ")
midi_to_txt(file)

# midi_to_txt('C:/Users/Asus/Documents/Development/Python/FuckingStupidMidi/amogus.mid')