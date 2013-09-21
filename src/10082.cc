#include <iostream>
#include <map>
#include <string>

#define uint unsigned int

using namespace std;

string keyboard[] = {
  "`1234567890-=",
  "QWERTYUIOP[]\\",
  "ASDFGHJKL;'",
  "ZXCVBNM,./",
  "  " };

map<char, char> createTransform() {
  map<char, char> t;
  for(int i = 0; i < 5; i++) {
    for(uint j = 1; j < keyboard[i].length(); j++) {
      t.insert(pair<char, char>(keyboard[i][j], keyboard[i][j - 1]));
    }
  }
  return t;
} 

int main() {
  string line;
  while(getline(cin, line)) {
    map<char, char> transform = createTransform();
    for(uint i = 0; i < line.length(); i++) {
      line[i] = transform[line[i]];
    }
    cout << line << endl;
  }
  return 0;
}