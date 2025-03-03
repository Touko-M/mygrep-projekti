#include <iostream>
#include "mygrep.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc == 3) {
        //käyttäjä antoi tiedoston ja hakusanan komentorivillä
        //haetaan tiedostosta ja tulostetaan osuvat rivit
        searchInFile(argv[2], argv[1]);  
    }   //molemmat kohdat saadaan siis selville argument countilla
    else if (argc == 1) {
        //käyttäjä ei antanut tiedostoa ja kysytään syötteet
        string text, pattern;

        cout << "Give a string from which to search for: ";
        getline(cin, text); //käytetään erkin suosittelemaa getlinea
        //cin:in sijaan niin luetaan koko rivi
        cout << "Give search string: ";
        getline(cin, pattern); //luetaan käyttäjän haku

        const char* textPtr = text.c_str(); //Muunnetaan string => char*
        const char* patternPtr = pattern.c_str();

        int position = findSubstring(textPtr, patternPtr); //haetaan hakusana tekstistä

        if (position != -1) {
            cout << "\"" << pattern << "\" found in \"" << text << "\" at position " << position << endl;
        } else {
            cout << "\"" << pattern << "\" NOT found in \"" << text << "\"" << endl;
        }
    }
    else {
        //Syötettiin väärin => näytetään ohje
        cout << "Usage:\n";
        cout << "  ./mygrep               (to search from user input)\n";
        cout << "  ./mygrep <pattern> <file>  (to search in file)\n";
    }
    return 0;
}
