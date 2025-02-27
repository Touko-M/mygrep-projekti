 #include "mygrep.hpp"

 using namespace std;

 //etsii löytyykö pattern textistä
 //palauttaa ensimmäisen indexin tai -1 jos ei löydy
 int findSubstring(const string& text, const string& pattern){
    if(pattern.empty()) return -1; //jos ei löydy palautetaan -1

    //muunnetaan string char*-osoittimiksi
    const char* textPtr = text.c_str();
    const char* patternPtr =pattern.c_str();

    //merkkijono päättyy null eli '\0'
    //käydään läpi isoa merkkijonoa, kunnes saavutetaan '\0'
    for(const char* t =textPtr; *t != '\0'; t++) {
        const char* tempT = t;
        const char* tempP = patternPtr;

        //verrataan merkkejä
        while (*tempT != '\0' && *tempP != '\0' && *tempT == *tempP) {
            tempT++;
            tempP++;
        }
        //jos hakusana täsmää, palautetaan indexi
        if (*tempP == '\0')
            return t - textPtr; //indexi lasketaan osoitineroituksesta
    }
    return -1; //hakusanaa ei löytynyt
    
 }