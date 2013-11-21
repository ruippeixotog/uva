#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

#define MAXN 100
#define MAXM 10000

#define INF 1e9

using namespace std;

// Union find
#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
vector<int> pset(1000); // 1000 is just an initial number, it is user-adjustable.
void initSet(int _size) { pset.resize(_size); REP (i, 0, _size - 1) pset[i] = i; }
int findSet(int i) { return (pset[i] == i) ? i : (pset[i] = findSet(pset[i])); }
void unionSet(int i, int j) { pset[findSet(i)] = findSet(j); }
bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

int n, m;
pair<int, pair<int, int> > edges[MAXM];
int mst[MAXN];

int findMst(bool setMst) {
  initSet(n);
  int cost = 0, conn = 0;
  for(int i = 0; conn < n - 1; i++) {
    if(i == m) return INF;
    if(edges[i].first == -1) continue;

    pair<int, int>& points = edges[i].second;
    if(!isSameSet(points.first, points.second)) {
      unionSet(points.first, points.second);
      cost += edges[i].first;
      if(setMst) mst[conn++] = i;
      else conn++;
    }
  }
  return cost;
}

int main() {
  int t; cin >> t;
  while(t--) {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
      int a, b, c; cin >> a >> b >> c;
      edges[i] = make_pair(c, make_pair(--a, --b));
    }
    sort(edges, edges + m);

    initSet(n);
    int mstCost = findMst(true);

    int smstCost = INF;
    for(int i = 0; i < n - 1; i++) {
      int oldCost = edges[mst[i]].first;
      edges[mst[i]].first = -1;
      smstCost = min(smstCost, findMst(false));
      edges[mst[i]].first = oldCost;
    }
    cout << mstCost << " " << smstCost << endl;
  }
  return 0;
}
