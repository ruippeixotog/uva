#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>

#define sq(x) ((x) * (x))

#define MAXS 100
#define MAXP 500

using namespace std;

// Union find
#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
vector<int> pset(1000); // 1000 is just an initial number, it is user-adjustable.
void initSet(int _size) { pset.resize(_size); REP (i, 0, _size - 1) pset[i] = i; }
int findSet(int i) { return (pset[i] == i) ? i : (pset[i] = findSet(pset[i])); }
void unionSet(int i, int j) { pset[findSet(i)] = findSet(j); }
bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

pair<int, int> op[MAXP];
pair<double, pair<int, int> > edges[MAXP * MAXP];

int main() {
  int t; cin >> t;
  while(t--) {
    int s, p; cin >> s >> p;
    int e = 0;
    for(int i = 0; i < p; i++) {
      cin >> op[i].first >> op[i].second;
      for(int j = 0; j < i; j++) {
        double dist = sqrt(sq(op[i].first - op[j].first) +
          sq(op[i].second - op[j].second));
        edges[e++] = make_pair(dist, make_pair(i, j));
      }
    }
    sort(edges, edges + e);

    initSet(p);
    double last = 0;
    int conn = 0;
    for(int i = 0; i < e && conn < p - s; i++) {
      pair<int, int>& points = edges[i].second;
      if(!isSameSet(points.first, points.second)) {
        unionSet(points.first, points.second);
        last = edges[i].first;
        conn++;
      }
    }
    printf("%.2f\n", last);
  }
  return 0;
}
