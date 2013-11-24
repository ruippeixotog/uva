#include <cstring>
#include <iostream>
#include <utility>
#include <vector>

#define MAXN 1000

using namespace std;

vector<pair<int, int> > graph[MAXN];
int dist[MAXN];

int main() {
  int t; cin >> t;
  while(t--) {
    int n, m; cin >> n >> m;

    for(int i = 0; i < n; i++) graph[i].clear();
    for(int i = 0; i < m; i++) {
      int x, y, t; cin >> x >> y >> t;
      graph[x].push_back(make_pair(y, t));
    }

    memset(dist, 0x3f, n * sizeof(int));
    dist[0] = 0;
    bool improved = true;
    for(int k = 0; k <= n && improved; k++) {
      improved = false;
      for(int i = 0; i < n; i++) {
        for(int j = 0; j < (int) graph[i].size(); j++) {
          int newDist = dist[i] + graph[i][j].second;
          if(newDist < dist[graph[i][j].first]) {
            improved = true;
            dist[graph[i][j].first] = newDist;
          }
        }
      }
    }
    cout << (improved ? "possible" : "not possible") << endl;
  }
  return 0;
}
