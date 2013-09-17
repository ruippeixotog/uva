#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define uint unsigned int

using namespace std;

int encodings[] = {0, 1, 2, 3, 0, 1, 2, 0, 0, 2, 2, 4, 5, 5, 0, 1, 2, 6, 2, 3,
  0, 1, 0, 2, 0, 2};

inline int encode(char c) {
  return encodings[c - 'A'];
}

string spaces(int n) {
  string sp;
  while(n--) sp += " ";
  return sp;
}

int main() {
  cout << spaces(9) << "NAME" << spaces(21) << "SOUNDEX CODE" << endl;

  string name;
  while(getline(cin, name)) {
    name.erase(name.end() - 1);
    cout << spaces(9) << name << spaces(25 - name.length()) << name[0];

    vector<int> codes;
    int lastCode = encode(name[0]);

    for(uint i = 1; i < name.length(); i++) {
      int code = encode(name[i]);
      if(code != lastCode) {
        if(code != 0) codes.push_back(code);
        lastCode = code;
      }
    }

    while(codes.size() < 3)
      codes.push_back(0);

    for(int i = 0; i < 3; i++)
      cout << codes[i];
    cout << endl;
  }
  cout << spaces(19) << "END OF OUTPUT" << endl;
  return 0;
}