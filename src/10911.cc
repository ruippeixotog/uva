#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

#define bit(b) (1 << (b))

#define MAXN 16
#define INF 1e8

using namespace std;

int n, x[MAXN], y[MAXN];
double dist[MAXN][MAXN], mem[1 << MAXN];

double minCost(int state, double cost) {
  if(mem[state] >= 0) return mem[state];
  if(state == bit(n) - 1) return cost;

  int idx = 0;
  while(state & bit(idx)) idx++;
  state |= bit(idx);

  double best = INF;
  for(int i = idx + 1; i < n; i++) {
    if(!(state & bit(i))) {
      best = min(best,
        minCost(state | bit(i), cost + dist[idx][i]));
    }
  }
  return mem[state] = best;
}

int main() {
  int tc = 0;
  while(cin >> n && n > 0) {
    n *= 2;
    string name;
    for(int i = 0; i < n; i++) {
      cin >> name >> x[i] >> y[i];

      for(int j = 0; j < i; j++)
        dist[j][i] = dist[i][j] = sqrt(
          (x[i] - x[j]) * (x[i] - x[j]) +
          (y[i] - y[j]) * (y[i] - y[j]));
    }

    memset(mem, -1, sizeof mem);
    printf("Case %d: %.2f\n", ++tc, minCost(0, 0.0));
  }
  return 0;
}
