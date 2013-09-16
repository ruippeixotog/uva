#include <cctype>
#include <cstdio>
#include <iostream>

#define uint unsigned int

using namespace std;

int main() {

  string line;
  while(getline(cin, line)) {
    uint begin = 0;
    uint cur = 0;
    while(cur < line.length()) {
      while(cur < line.length() && isspace(line[cur])) cur++;
      if(cur == line.length()) break;

      begin = cur;
      while(cur < line.length() && !isspace(line[cur])) cur++;

      for(uint i = 0; i < (cur - begin) / 2; i++) {
        char tmp = line[begin + i];
        line[begin + i] = line[cur - i - 1];
        line[cur - i - 1] = tmp;
      }
    }
    cout << line << endl;
  }
  return 0;
}