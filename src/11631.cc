#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

#define ll long long

#define MAXM 200000
#define MAXN 200000

using namespace std;

// Union find
#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
vector<int> pset(1000); // 1000 is just an initial number, it is user-adjustable.
void initSet(int _size) { pset.resize(_size); REP (i, 0, _size - 1) pset[i] = i; }
int findSet(int i) { return (pset[i] == i) ? i : (pset[i] = findSet(pset[i])); }
void unionSet(int i, int j) { pset[findSet(i)] = findSet(j); }
bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

pair<ll, pair<int, int> > edges[MAXN];

int main() {
  int n, m;
  while(cin >> m >> n && m > 0) {
    for(int i = 0; i < n; i++) {
      int x, y, z; cin >> x >> y >> z;
      edges[i] = make_pair(z, make_pair(x, y));
    }
    sort(edges, edges + n);

    initSet(m);
    ll total = 0, mst = 0;
    for(int i = 0; i < n; i++) {
      total += edges[i].first;

      pair<int, int>& points = edges[i].second;
      if(!isSameSet(points.first, points.second)) {
        unionSet(points.first, points.second);
        mst += edges[i].first;
      }
    }
    cout << (total - mst) << endl;
  }
  return 0;
}
