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
bool found;

void printOrderings(int used, int usedSize) {
  if(usedSize == (int) vars.size()) {
    found = true; cout << curr << endl; return;
  }
  for(int i = 0; i < (int) vars.size(); i++) {
    int v = vars[i];
    if(!contains(used, v) && ((used & deps[v]) == deps[v])) {
      if(!curr.empty()) curr.push_back(' ');
      curr.push_back(v + 'A');
      printOrderings(used | bit(v), usedSize + 1);
      curr.erase(curr.end() - 1);
      if(!curr.empty()) curr.erase(curr.end() - 1);
    }
  }
}

int main() {
  int t; cin >> t;
  string line; getline(cin, line);
  while(t--) {
    getline(cin, line); getline(cin, line);

    vars.clear();
    for(int i = 0; i < (int) line.length(); i += 2) {
      vars.push_back(line[i] - 'A');
      deps[line[i] - 'A'] = 0;
    }
    sort(vars.begin(), vars.end());

    getline(cin, line);
    for(int i = 0; i < (int) line.length(); i += 4)
      deps[line[i + 2] - 'A'] |= bit(line[i] - 'A');

    found = false;
    printOrderings(0, 0);
    if(!found) cout << "NO" << endl;
    if(t) cout << endl;
  }
  return 0;
}
