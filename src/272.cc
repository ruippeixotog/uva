#include <iostream>

#define uint unsigned int

using namespace std;

int main() {
  string quotes[] = {"``", "''"};
  int qidx = 0;

  string line;
  while(getline(cin, line)) {
    for(uint i = 0; i < line.size(); i++) {
      if(line[i] == '"') {
        line = line.replace(i, 1, quotes[qidx]);
        qidx = 1 - qidx;
      }
    }
    cout << line << endl;
  }
  return 0;
}