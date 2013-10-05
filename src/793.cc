#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
vector<int> pset(1000); // 1000 is just an initial number, it is user-adjustable.
void initSet(int _size) { pset.resize(_size); REP (i, 0, _size - 1) pset[i] = i; }
int findSet(int i) { return (pset[i] == i) ? i : (pset[i] = findSet(pset[i])); }
void unionSet(int i, int j) { pset[findSet(i)] = findSet(j); }
bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

int main() {
  int t, n; string line;
  cin >> t;
  while(t--) {
    cin >> n;
    getline(cin, line);

    initSet(n + 1);
    int conn = 0, notConn = 0;
    while(getline(cin, line) && !line.empty()) {
      char type; int a, b;
      istringstream sin(line); sin >> type >> a >> b;
      if(type == 'c') unionSet(a, b);
      else (isSameSet(a, b) ? conn : notConn)++;
    }
    cout << conn << "," << notConn << endl;
    if(t) cout << endl;
  }
  return 0;
}