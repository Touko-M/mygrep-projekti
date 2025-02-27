 #ifndef MYGREP_HPP //estetään tiedoston moninkertainen säilytys
 #define MYGREP_HPP //määrittää MYGREP_HPP-tunnisteen
 #include <string>

 using namespace std;

 //etsii kohteen annetusta tekstistä
 //parametrit: text ja pattern
 //palautus: ensimmäinen indeksi tai -1 jos ei löydy
 int findSubstring(const string& text, const string& pattern);

 #endif //MYGREP_HPP
