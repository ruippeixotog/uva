#include <iostream>
#include <string>

#define uint unsigned int

using namespace std;

int main() {
  string orig, enc;
  while(cin >> orig >> enc) {
    uint oIdx = 0;
    for(uint i = 0; i < enc.length(); i++) {
      if(enc[i] == orig[oIdx]) {
        if(++oIdx == orig.length()) break; 
      }
    }
    cout << (oIdx == orig.length() ? "Yes" : "No") << endl;
  }
  return 0;
}
