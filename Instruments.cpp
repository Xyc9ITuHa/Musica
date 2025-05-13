//
// Created by хус on 13.05.2025.
//

#include "Instruments.h"

#include <utility>
void Instrument::SetName(std::string name) { this->name = std::move(name); }

std::ostream& operator<<(std::ostream& os, const std::vector<std::string>& vec) {
    for (const auto& str : vec) {
        os << str << '\n';
    }
    return os;
}

void Instrument::showPlayableNotes() const {
    std::cout << this->playableNotes << std::endl;
}
void StringInstrument::AssignFrets(short int frets) {
    this->frets = frets;
}
void StringInstrument::AssignStrings(short int Strings) {
    this->Strings = Strings;
}
void StringInstrument::ComputeNotes() {
    // some very complex code
    //maybe later
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
