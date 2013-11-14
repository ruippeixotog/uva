#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>

#define sq(x) ((x) * (x))

#define MAXN 750
#define MAXM 1000

using namespace std;

// Union find
#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
vector<int> pset(1000); // 1000 is just an initial number, it is user-adjustable.
void initSet(int _size) { pset.resize(_size); REP (i, 0, _size - 1) pset[i] = i; }
int findSet(int i) { return (pset[i] == i) ? i : (pset[i] = findSet(pset[i])); }
void unionSet(int i, int j) { pset[findSet(i)] = findSet(j); }
bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

pair<int, int> bld[MAXN];
pair<double, pair<int, int> > edges[MAXN * MAXN];

int main() {
  int n;
  while(cin >> n) {
    int e = 0;
    for(int i = 0; i < n; i++) {
      cin >> bld[i].first >> bld[i].second;
      for(int j = 0; j < i; j++) {
        double dist = sqrt(sq(bld[i].first - bld[j].first) +
          sq(bld[i].second - bld[j].second));
        edges[e++] = make_pair(dist, make_pair(i, j));
      }
    }
    sort(edges, edges + e);

    initSet(n);
    int m, a, b; cin >> m;
    for(int i = 0; i < m; i++) {
      cin >> a >> b; unionSet(a - 1, b - 1);
    }

    double mst = 0;
    for(int i = 0; i < e; i++) {
      pair<int, int>& points = edges[i].second;
      if(!isSameSet(points.first, points.second)) {
        unionSet(points.first, points.second);
        mst += edges[i].first;
      }
    }
    printf("%.2f\n", mst);
  }
  return 0;
}
