#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>

#define bit(b) (1 << (b))

#define MAXN 16
#define INF 1e8

using namespace std;

int n, x[MAXN], y[MAXN];

double dist(int i, int j) {
  return sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));
}

double minCost(int state, double cost) {
  if(state == 0) return cost;

  int idx = 0;
  while(!(state & bit(idx))) idx++;
  state &= ~bit(idx);

  double best = INF;
  for(int i = idx + 1; i < n; i++) {
    if(state & bit(i)) {
      best = min(best,
        minCost(state & ~bit(i), cost + dist(idx, i)));
    }
  }
  return best;
}

int main() {
  while(cin >> n && n > 0) {
    n *= 2;
    string name;
    for(int i = 0; i < n; i++) cin >> name >> x[i] >> y[i];
    printf("%.2f\n", minCost(bit(n) - 1, 0.0));
  }
  return 0;
}
