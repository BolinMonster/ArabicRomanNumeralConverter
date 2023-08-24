#include <iostream>
#include <cstdlib>
#include <map>
#include <vector>

using namespace std;

string arabicToRoman(int arabic);
int romanToArabic(string roman);

/**
 * utilisation d'un vector au lieu d'une map pour préserver l'ordre
*/
const vector<pair<int, string>> arabicToRomanArray = {
  {1000, "M"},
  {900, "CM"},
  {500, "D"},
  {400, "CD"},
  {100, "C"},
  {90, "XC"},
  {50, "L"},
  {40, "XL"},
  {10, "X"},
  {9, "IX"},
  {5, "V"},
  {4, "IV"},
  {1, "I"}
};


map<char, int> romanToArabicMap = {
  {'I', 1},
  {'V', 5},
  {'X', 10},
  {'L', 50},
  {'C', 100},
  {'D', 500},
  {'M', 1000}
};

int main() {
  // Test de la fonction ArabicToRoman
  int arabicNumber;
  cout << "Enter a number in Arabic numerals:\n";
  cin >> arabicNumber;
  string romanEquivalent = arabicToRoman(arabicNumber);
  cout << "Translation to Roman numerals: " << romanEquivalent << endl;

  // Testing the RomanToArabic function
  string romanNumber;
  cout << "Enter Roman numerals:\n";
  cin >> romanNumber;
  int arabicEquivalent = romanToArabic(romanNumber);
  cout << "Translation to Arabic number: " << arabicEquivalent << endl;

  return EXIT_SUCCESS;
}

string arabicToRoman(int arabic) {
  string result = "";
  for (const auto& entry : arabicToRomanArray) {
      while (arabic >= entry.first) {
          result += entry.second;
          arabic -= entry.first;
      }
  }
  return result;
}

int romanToArabic(string roman) {
  int result = 0;
  for (int i = 0; i < roman.length(); i++) {
      int current = romanToArabicMap[roman[i]];
      if (i + 1 < roman.length()) {
          int next = romanToArabicMap[roman[i + 1]];
          if (current >= next) {
              result += current;
          } else {
              result += next - current;
              i++;
          }
      } else {
          result += current;
      }
  }
  return result;
}