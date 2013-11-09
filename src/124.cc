#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

#define bit(b) (1 << (b))
#define contains(n, b) ((n) & bit(b))

#define MAXV 26

using namespace std;

vector<int> vars;
int deps[MAXV];

string curr;

void printOrderings(int used, int usedSize) {
  if(usedSize == (int) vars.size()) {
    cout << curr << endl; return;
  }
  for(int i = 0; i < (int) vars.size(); i++) {
    int v = vars[i];
    if(!contains(used, v) && ((used & deps[v]) == deps[v])) {
      curr.push_back(v + 'a');
      printOrderings(used | bit(v), usedSize + 1);
      curr.erase(curr.end() - 1);
    }
  }
}

int main() {
  int tc = 0; string line;
  while(getline(cin, line)) {
    if(tc++) cout << endl;

    vars.clear();
    for(int i = 0; i < (int) line.length(); i += 2) {
      vars.push_back(line[i] - 'a');
      deps[line[i] - 'a'] = 0;
    }
    sort(vars.begin(), vars.end());

    getline(cin, line);
    for(int i = 0; i < (int) line.length(); i += 4)
      deps[line[i + 2] - 'a'] |= bit(line[i] - 'a');

    printOrderings(0, 0);
  }
  return 0;
}
