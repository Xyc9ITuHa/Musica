#include "Instruments.h"
#include <iostream>
#include <memory>
#include <vector>

// Function to display instrument information
void displayInstrumentInfo(const std::string& title, Instrument* instrument) {
    std::cout << "\n====== " << title << " ======" << std::endl;
    std::cout << "Name: " << instrument->name << std::endl;
    
    // Show playable notes
    std::cout << "Playable notes:" << std::endl;
    instrument->showPlayableNotes();
}

int main() {
    std::cout << "Musical Instruments Demonstration" << std::endl;
    
    // Create vector to store instruments using polymorphism
    std::vector<std::unique_ptr<Instrument>> instruments;
    
    // Create different instruments
    auto ukulele = std::make_unique<Ukulele>();
    auto piano = std::make_unique<GrandPiano>();
    auto rockstar = std::make_unique<GuitarPianoRockstar>();
    
    // Display information about each instrument
    displayInstrumentInfo("Ukulele", ukulele.get());
    displayInstrumentInfo("Grand Piano", piano.get());
    displayInstrumentInfo("Guitar Piano Rockstar", rockstar.get());
    
    // Demonstrate special feature of GuitarPianoRockstar
    std::cout << "\nDemonstrating Guitar Piano Rockstar special feature:" << std::endl;
    rockstar->PlayRiff();
    
    // Create a custom StringInstrument
    auto guitar = std::make_unique<StringInstrument>();
    guitar->SetName("Custom Guitar");
    guitar->AssignStrings(6);
    guitar->AssignFrets(24);
    guitar->ComputeNotes();
    
    displayInstrumentInfo("Custom Guitar", guitar.get());
    
    // Add instruments to the vector
    instruments.push_back(std::move(ukulele));
    instruments.push_back(std::move(piano));
    instruments.push_back(std::move(rockstar));
    instruments.push_back(std::move(guitar));
    
    // Show all instruments using polymorphism
    std::cout << "\n====== All Instruments ======" << std::endl;
    for (const auto& instrument : instruments) {
        std::cout << "- " << instrument->name << std::endl;
    }
    
    std::cout << "\nProgram completed successfully." << std::endl;
    return 0;
}