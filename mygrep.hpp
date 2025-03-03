 #ifndef MYGREP_HPP //estetään tiedoston moninkertainen säilytys
 #define MYGREP_HPP //määrittää MYGREP_HPP-tunnisteen
 #include <string>

 using namespace std;

 //etsii kohteen annetusta tekstistä
 //parametrit: text(etsittävä teksti) ja pattern(hakusana)
 //palautus: ensimmäinen indeksi tai -1 jos ei löydy
 int findSubstring(const char* text, const char* pattern);
 //etsii kohteen tiedostosta rivi kerrallaan ja tulostaa löytyneet
 //parametrit: filename(tiedoston nimi) ja pattern(hakusana)
 void searchInFile(const char* filename, const char* pattern);

 #endif //MYGREP_HPP
