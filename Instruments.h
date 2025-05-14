//
// Created by хус on 13.05.2025.
//

#ifndef INSTRUMENTS_H
#define INSTRUMENTS_H
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>

class Instrument {
    std::vector<std::string> notation;
    std::vector<std::string> playableNotes;
public:
    std::string name;
    Instrument();
    virtual ~Instrument();
    void playNote();
    void sayNotation();
    virtual void showPlayableNotes() const;
    void playChord();
    void SetName(std::string name);
    virtual void showParams();
};

class StringInstrument: public Instrument {
    unsigned short int Strings = 6; // 6 by default
    std::vector<std::string> tuning = { "E2", "A2", "D3", "G3", "B3", "E4" }; // from the lowest string to highest
    unsigned short int frets = 12; // typical fret count
    public:
    void ComputeNotes();
    void AssignStrings(short int Strings);
    void AssignFrets(short int frets);
    void showPlayableNotes() const override;
    void showParams() override;
};

class KeyInstrument: public Instrument {
    unsigned int blackKeys = 36;
    unsigned short int whiteKeys = 52;
    unsigned short int Keys = 88;
    unsigned short int Octaves = 7;
    bool firstPedal = false;
    bool secondPedal = false;
    public:
    void AssignKeys(short int white, short int black);
    void AssignOctaves(short int octaves);
    void showPlayableNotes() const override;
};

class GrandPiano: public KeyInstrument {
    public:
    GrandPiano();
};

class GuitarPianoRockstar: public KeyInstrument {
    public:
    GuitarPianoRockstar();
    void PlayRiff();
};

class Ukulele: public StringInstrument {
    public:
    Ukulele();
};

#endif //INSTRUMENTS_H
