#include <cstdio>
#include <iostream>
#include <map>
#include <string>

#define miterator map<string, int>::iterator

using namespace std;

int main() {
  int n; string line;
  cin >> n;
  getline(cin, line); getline(cin, line);

  while(n--) {
    int total = 0;
    map<string, int> count;
    while(getline(cin, line) && !line.empty()) {
      count[line]++; total++;
    }
    for(miterator it = count.begin(); it != count.end(); it++) {
      printf("%s %.4f\n",
        it->first.c_str(), 100 * it->second / (double) total);
    }
  }
  return 0;
}
