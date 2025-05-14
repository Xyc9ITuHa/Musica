//
// Created by хус on 13.05.2025.
//

#include "Instruments.h"

#include <utility>
void Instrument::SetName(std::string name) { this->name = std::move(name); }
void Instrument::showParams() {
    std::cout << "that's just a " << std::endl;
}

std::ostream &operator<<(std::ostream &os, const std::vector<std::string> &vec) {
    for (const auto &str: vec) {
        os << str << '\n';
    }
    return os;
}

Instrument::Instrument() {
    name = "Casual Bongos";
    playableNotes.clear();
}
Instrument::~Instrument() = default;

void Instrument::playNote() { std::cout << "\nPlaying note on" << name << std::endl; }
void Instrument::sayNotation() { std::cout << notation << std::endl; };

void Instrument::showPlayableNotes() const { std::cout << this->playableNotes << std::endl; }
void Instrument::playChord() { std::cout << "well i guess it has no chords\n"; }
void StringInstrument::AssignFrets(short int frets) { this->frets = frets; }
void StringInstrument::showPlayableNotes() const { Instrument::showPlayableNotes(); }

void StringInstrument::showParams() {
    std::cout << "Strings: " << this->Strings << std::endl;
    std::cout << "Frets: " << this->frets << std::endl;
    std::cout << "Tuning: " << this->tuning << std::endl;
}

void StringInstrument::AssignStrings(short int Strings) {
    this->Strings = Strings;
}
void StringInstrument::ComputeNotes() {
    // some very complex code
    //maybe later
}

void KeyInstrument::AssignKeys(short int white, short int black) {
    this->whiteKeys = white;
    this->blackKeys = black;
    this->Keys = white + black;

    // Calculate appropriate octave count
    this->Octaves = (this->Keys + 3) / 12; // +3 for rounding up
}

void KeyInstrument::AssignOctaves(short int octaves) {
    this->Octaves = octaves;

    // Approximate key count based on octaves (12 keys per octave)
    this->Keys = this->Octaves * 12;
    this->whiteKeys = this->Octaves * 7 + 1; // +1 for the final C
    this->blackKeys = this->Keys - this->whiteKeys;
}

void KeyInstrument::showPlayableNotes() const {
    std::cout << "Playable notes for " << this->name << " (" << this->Keys << " keys: "
              << this->whiteKeys << " white, " << this->blackKeys << " black)" << std::endl;

    std::cout << "Octave range: " << this->Octaves << " octaves" << std::endl;

    // Display notes organized by octave with white and black keys separated
    Instrument::showPlayableNotes();
}
Ukulele::Ukulele(){
    SetName("Ukulele");
    AssignFrets(15);
    AssignStrings(4);
    ComputeNotes();
}

 GrandPiano::GrandPiano() {
    SetName("Grand Piano");
    AssignKeys(52, 36);
    AssignOctaves(7);
}

 GuitarPianoRockstar::GuitarPianoRockstar() {
    SetName("Guitar Piano Rockstar");
    AssignKeys(36, 24); // I'm a bit lazy to count them
    AssignOctaves(4);
}
void GuitarPianoRockstar::PlayRiff() { std::cout << "chicka chika chew chiwewe a cho" << std::endl; };


