'''
This python script converts midi files to frequencies that can be used with the `Grove Speaker`
and it exports them in a .txt file for future processing.
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
Where frequency, duration, and delay are Integers.
'''
def midi_to_txt(filename, melodyInstrument='Piano'):

    try:
        midi = converter.parse(filename)
    except FileNotFoundError:
        print('File not found')
    
    # # Extract tempo information
    # tempo = midi.flat.get('MetronomeMark')
    # if tempo:
    #     bpm = int(tempo.getQuarterBPM())
    #     print(f"BPM: {bpm}")

    # Extract tempo information
    bpm = None
    for element in midi.flat:
        if 'MetronomeMark' in element.classes:
            bpm = element.number
            break

    if bpm:
        print(f"BPM: {bpm}")
    else:
        bpm = 60

    quarterNoteDuration = getQuarterNoteDuration(bpm)
    print(f'Duration of a quarter note in seconds: {quarterNoteDuration}')

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
        main_instrument_index = instrument_names.index(melodyInstrument)
    except ValueError:
        print('%s does not have any Piano part' % filename)
        return None
    
    notes_to_parse = parts.parts[main_instrument_index].recurse()

    for element in notes_to_parse:
        
        # We make sure that we only get the individual notes,
        # not the chords
        if isinstance(element, note21.Note):
            freq = str(noteToGroveFrequency(element.pitch.midi))
            if (freq == 'None'):
                continue
            duration = check_float(str(element.duration)[27:-1], quarterNoteDuration)
            delay = check_float(str(element.offset), quarterNoteDuration) # Need to fix this to get the distance between notes
            notes.append([freq, duration, delay])
    
    baseFilename = os.path.splitext(filename)[0]
    outputFilename = f"{baseFilename}_delay.txt"

    with open(outputFilename, "w") as f:
        for i, n in enumerate(notes):
            currentDelay = 0

            '''
            If it is not the last note, we calculate the delay as it follows:
                nextOffset - currentOffset - currentDuration
            Otherwise, we assign a delay of 0.
            '''
            if(not i >= len(notes) - 1):
                nextOffset = int(notes[i + 1][2])
                currentOffset = int(n[2])
                currentDuration = int(n[1])

                currentDelay = nextOffset - currentOffset - currentDuration

                currentDelay = currentDelay if currentDelay >= 0 else 0

            f.write(f"\u007b{n[0]},{n[1]},{currentDelay}\u007d")
            if i < len(notes) - 1:
                f.write(",\n")
            else:
                f.write("\n")

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
def check_float(duration, quarter_note_duration=100):
    if('/' in duration):
        numerator = float(duration.split('/')[0])
        denominator = float(duration.split('/')[1])
        duration = float(numerator/denominator)
    
    durationInMilliseconds = 1
    durationInMilliseconds = float(duration) * quarter_note_duration
    return round(durationInMilliseconds)

def getQuarterNoteDuration(bpm):
    return round((float(bpm) / 60) * 100)

file = input('Enter the path of the file: ')
mainInstrument = input('Enter the main instrument you would like to parse: (d: Piano) ')

if mainInstrument == '':
    midi_to_txt(file)
else:
    midi_to_txt(file, mainInstrument)

print(f'The file was stored in: {file}')
print(f'Thanks for using this script! :)\n')
