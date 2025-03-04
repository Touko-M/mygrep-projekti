 #ifndef MYGREP_HPP //estetään tiedoston moninkertainen säilytys
 #define MYGREP_HPP //määrittää MYGREP_HPP-tunnisteen
 #include <string>

 using namespace std;

 //etsii haettavan merkkijonon annetusta tekstistä
 int findSubstring(const char* text, const char* pattern);
 
 //etsii hakusanaa tiedostosta ja tulostaa osuvat rivit
 //mahdollisuus näyttää rivinumerot (-l) ja laskea osumat (-o)
 void searchInFile(const char* filename, const char* pattern, bool showLineNumbers, bool showOccurrences);

 #endif //MYGREP_HPP
