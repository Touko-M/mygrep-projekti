#include "mygrep.hpp"  // Sisältää funktioiden esittelyt
#include <iostream>     // Tulostusta varten (cout, cerr)
#include <fstream>      // Tiedostonlukua varten (ifstream)

using namespace std;

// Etsii hakusanan annetusta tekstistä
// Palauttaa ensimmäisen osuman indeksin tai -1, jos ei löydy
int findSubstring(const char* text, const char* pattern) {
    if (*pattern == '\0') return -1;  // Jos hakusana on tyhjä, palautetaan -1

    const char* t = text;  // Osoitin tekstin alkuun

    // Käydään teksti läpi merkki kerrallaan
    while (*t != '\0') {
        const char* tempT = t;
        const char* tempP = pattern;

        // Tarkistetaan, täsmääkö hakusana tästä kohdasta eteenpäin
        while (*tempT != '\0' && *tempP != '\0' && *tempT == *tempP) {
            tempT++;
            tempP++;
        }

        // Jos hakusana löytyi kokonaan, palautetaan sen alkamiskohta
        if (*tempP == '\0') {
            return t - text;  
        }

        t++;  // Siirrytään seuraavaan merkkiin
    }

    return -1;  // Hakusanaa ei löytynyt
}

// Etsii hakusanan tiedostosta ja tulostaa osumat
// Tukee optioita: -l (rivinumerot), -o (osumien määrä)
void searchInFile(const char* filename, const char* pattern, bool showLineNumbers, bool showOccurrences) {
    ifstream file(filename);  // Avataan tiedosto lukutilassa
    if (!file) {  
        cerr << "Error: Could not open file " << filename << endl;
        return;
    }

    string line;
    int lineNumber = 0; // Seuraa monennellako rivillä ollaan
    int matchCount = 0; // Seuraa kuinka monta osumaa löytyi

    // Luetaan tiedosto rivi kerrallaan
    while (getline(file, line)) {
        lineNumber++;  // Kasvatetaan rivinumeroa
        const char* linePtr = line.c_str();  // Muunnetaan string -> char*

        // Tarkistetaan, löytyykö hakusana tältä riviltä
        if (findSubstring(linePtr, pattern) != -1) {
            matchCount++;  // Lisätään osuma
            if (showLineNumbers) {
                cout << lineNumber << ": ";  // Tulostetaan rivinumero
            }
            cout << line << endl;  // Tulostetaan rivi
        }
    }

    file.close();  // Suljetaan tiedosto
    //ilmoitetaan jos ei osumia
     if (matchCount == 0) {
        cout << "No occurrences of \"" << pattern << "\" found in " << filename << endl;
    }

    // Jos käyttäjä halusi osumien lukumäärän, tulostetaan se
    if (showOccurrences) {
        cout << "Occurrences of lines containing \"" << pattern << "\": " << matchCount << endl;
    }
}
