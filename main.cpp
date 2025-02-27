#include <iostream>
#include "mygrep.hpp"

using namespace std;

int main() {
    string text, pattern;  // text = iso merkkijono ja pattern = etsittävä kohde (pieni merkkijono)

    // Pyydetään isoa merkkijonoa
    cout << "Give a string from which to search for: ";
    getline(cin, text);  // Käytetään getline(), jotta luetaan koko rivi

    // Pyydetään pientä merkkijonoa
    cout << "Give search string: ";
    getline(cin, pattern);

    // Kutsutaan funktiota, joka etsii pienen merkkijonon (pattern) tekstistä
    int position = findSubstring(text, pattern);

    // Käytetään ternary operatoria, siistimpi tapa tehdä if-else
    cout << "\"" << pattern << "\" "
     << (position != -1 ? "Found in \"" : "Not found in \"") 
     << text 
     << (position != -1 ? "\" in position " + to_string(position) : "\"") 
     << endl;


    return 0; 
} 