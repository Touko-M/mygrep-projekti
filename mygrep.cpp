 #include "mygrep.hpp"
 #include <iostream>
 #include <fstream>

 using namespace std;

 //etsii löytyykö pattern textistä
 //käydään osoittimilla tekstin merkit läpi yksi kerrallaan
 int findSubstring(const char* text, const char* pattern){
    if(*pattern=='\0') return -1; //tyhjä niin palautetaan -1

    const char* t = text; //osoitin tekstin alkuun

    while (*t != '\0'){ //käydään läpi isoa merkkijonoa
        const char* tempT= t;
        const char* tempP= pattern;

        //verrataan merkkejä yksi kerrallaan
        while (*tempT != '\0' && *tempP != '\0' && *tempT == *tempP){
            tempT++;
            tempP++;
        }

        //jos pattern löytyi kokonaan, palautetaan sen sijainti
        if(*tempP=='\0') {
            return t - text; //lasketaan osoitinero (sijainti tekstissä)
        }
        t++; //siirrytään seuraavaan merkkiin tekstissä
    }
    return -1; //ei löytynyt
 }

 //etsitään hakusana tiedostosta rivi kerrallaan
 void searchInFile(const char* filename, const char* pattern){
    ifstream file(filename); //avataan tiedosto
    if (!file){
        cerr << "Error could not open file " << filename << endl; //virheilmoitus jos tiedostoa ei voida avata
        return; //palataan takaisin pääohjelmaan
    }

    string line;
    
    while(!file.eof()){ //luetaan tiedosto rivi kerrallaan
        getline(file,line);
        const char* linePtr = line.c_str(); //muutetaan string osoittimeksi

        //jos rivi sisältää haetun merkkijonon, tulostetaan se
        if(findSubstring(linePtr, pattern) != -1){
            cout << line << endl;
        }
    }
    file.close(); //suljetaan tiedosto
 }
