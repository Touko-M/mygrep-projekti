#include <iostream>
#include "mygrep.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    // Tarkistetaan, onko käyttäjä syöttänyt oikean määrän argumentteja
    if (argc >= 3) {
        bool showLineNumbers = false;  // Pitääkö näyttää rivinumerot (-l)
        bool showOccurrences = false;  // Pitääkö laskea osumat (-o)
        const char* pattern;
        const char* filename;

        // Tarkistetaan, onko annettu optioita (-l ja/tai -o)
        if (argc == 4 && argv[1][0] == '-') {  
            // Käyttäjä antoi optioita, tutkitaan ne
            for (int i = 1; argv[1][i] != '\0'; i++) {  
                if (argv[1][i] == 'o') showOccurrences = true;  
                if (argv[1][i] == 'l') showLineNumbers = true;  
            }
            pattern = argv[2];  // Haettava merkkijono
            filename = argv[3]; // Tiedoston nimi
        } else {  
            // Ei optioita, käytetään normaalia hakua
            pattern = argv[1];
            filename = argv[2];
        }

        // Suoritetaan tiedoston haku käyttäjän antamilla asetuksilla
        searchInFile(filename, pattern, showLineNumbers, showOccurrences);
    } 
    else if (argc == 1) {
        // Käyttäjä ei antanut tiedostoa ja hakusanaa, kysytään syötteet
        string text, pattern;
        
        cout << "Give a string from which to search for: ";
        getline(cin, text);  // Luetaan koko käyttäjän antama rivi

        cout << "Give search string: ";
        getline(cin, pattern);  // Luetaan käyttäjän antama hakusana

        const char* textPtr = text.c_str();  // Muunnetaan string -> char*
        const char* patternPtr = pattern.c_str();

        int position = findSubstring(textPtr, patternPtr);

        if (position != -1) {
            cout << "\"" << pattern << "\" found in \"" << text << "\" at position " << position << endl;
        } else {
            cout << "\"" << pattern << "\" NOT found in \"" << text << "\"" << endl;
        }
    } 
    else {
        // Virheellinen syöte, näytetään käyttöohje
        cout << "Usage:\n";
        cout << "  ./mygrep <pattern> <file>          (search normally)\n";
        cout << "  ./mygrep -l <pattern> <file>      (show line numbers)\n";
        cout << "  ./mygrep -o <pattern> <file>      (show occurrences count)\n";
        cout << "  ./mygrep -ol <pattern> <file>     (show both line numbers and occurrences count)\n";
    }

    return 0;
}
