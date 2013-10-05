#include <iostream>
#include <map>
#include <vector>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
vector<int> pset(MAXN);
vector<int> psize(MAXN);
void initSingleSet(int i) { pset[i] = i; psize[i] = 1; }
int findSet(int i) { return (pset[i] == i) ? i : (pset[i] = findSet(pset[i])); }
int sizeOfSet(int i) { return psize[findSet(i)]; }
void unionSet(int i, int j) {
  if(findSet(j) != findSet(i)) psize[findSet(j)] += sizeOfSet(i);
  pset[findSet(i)] = findSet(j); }
bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

map<string, int> fid;
int nextFid = 0;
void resetIds() { fid.clear(); nextFid = 0; }
int setId(string& f) {
  if(!fid.count(f)) { initSingleSet(nextFid); fid[f] = nextFid++; }
  return fid[f];
}

int main() {
  int t, n;
  cin >> t;
  while(t--) {
    cin >> n;
    resetIds();

    while(n--) {
      string f1, f2;
      cin >> f1 >> f2;
      unionSet(setId(f1), setId(f2));
      cout << sizeOfSet(setId(f1)) << endl;
    }
  }
  return 0;
}
