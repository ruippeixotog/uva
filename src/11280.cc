#include <cstring>
#include <iostream>
#include <map>
#include <utility>
#include <vector>

#define MAXN 1000

#define INF 0x3f3f3f3f

using namespace std;

vector<pair<int, int> > graph[MAXN];

int cost[MAXN + 1][MAXN];

int main() {
  int t; cin >> t;
  for(int tc = 1; tc <= t; tc++) {
    if(tc > 1) cout << endl;

    int n; cin >> n;
    map<string, int> cityId;
    for(int i = 0; i < n; i++) {
      string city; cin >> city;
      cityId[city] = i;
      graph[i].clear();
    }

    int m; cin >> m;
    while(m--) {
      string ca, cb; int c;
      cin >> ca >> cb >> c;
      graph[cityId[ca]].push_back(make_pair(cityId[cb], c));
    }

    memset(cost[0], INF, sizeof(cost[0]));
    cost[0][0] = 0;

    for(int k = 1; k <= n; k++) {
      memcpy(cost[k], cost[k - 1], sizeof(cost[k]));

      for(int i = 0; i < n; i++) {
        if(cost[k - 1][i] == INF) continue;
        for(int j = 0; j < (int) graph[i].size(); j++) {
          int to = graph[i][j].first;
          cost[k][to] = min(cost[k][to],
            cost[k - 1][i] + graph[i][j].second);
        }
      }
    }

    cout << "Scenario #" << tc << endl;
    int nq; cin >> nq;
    while(nq--) {
      int q; cin >> q; q = min(q + 1, n);
      if(cost[q][n - 1] == INF) cout << "No satisfactory flights" << endl;
      else cout << "Total cost of flight(s) is $" <<
        cost[q][n - 1] << endl;
    }
  }
  return 0;
}
