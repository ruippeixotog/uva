#include <iostream>
#include <vector>

#define bit(b) (1 << (b))

#define MAXM 20

using namespace std;

int size[MAXM];
vector<int> sides;
int sideSize;

void genSides(int mask, int currSize, int k, int m) {
  if(currSize == sideSize) sides.push_back(mask);
  else if(k < m && currSize < sideSize) {
    genSides(mask, currSize, k + 1, m);
    genSides(mask | bit(k), currSize + size[k], k + 1, m);
  }
}

bool existsSq(int mask, int k) {
  if(k == 4) return true;
  for(int i = 0; i < (int) sides.size(); i++) {
    if(!(sides[i] & mask) && existsSq(mask | sides[i], k + 1))
      return true;
  }
  return false;
}

int main() {
  int t; cin >> t;

  while(t--) {
    int m; cin >> m;

    sideSize = 0;
    for(int i = 0; i < m; i++) {
      cin >> size[i];
      sideSize += size[i];
    }
    if(sideSize % 4 != 0) {
      cout << "no" << endl;
      continue;
    }
    sideSize /= 4;

    sides.clear();
    genSides(0, 0, 0, m);
    cout << (existsSq(0, 0) ? "yes" : "no") << endl;
  }
  return 0;
}
