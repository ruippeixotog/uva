#include <iostream>
#include <vector>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
vector<int> pset(26); // 1000 is just an initial number, it is user-adjustable.
void initSet(int _size) { pset.resize(_size); REP (i, 0, _size - 1) pset[i] = i; }
int findSet(int i) { return (pset[i] == i) ? i : (pset[i] = findSet(pset[i])); }
void unionSet(int i, int j) { pset[findSet(i)] = findSet(j); }
bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

int main() {
  int t; string line;
  cin >> t;
  getline(cin, line); getline(cin, line);

  while(t--) {
    getline(cin, line);
    int size = line[0] - 'A' + 1;
    initSet(size);

    int setCount = size;
    while(getline(cin, line) && !line.empty()) {
      if(!isSameSet(line[0] - 'A', line[1] - 'A')) {
        unionSet(line[0] - 'A', line[1] - 'A');
        setCount--;
      }
    }
    cout << setCount << endl;
    if(t) cout << endl;
  }
  return 0;
}
