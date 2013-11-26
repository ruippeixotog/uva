#include <cstring>
#include <iostream>

#define MAXN 100

using namespace std;

int dist[MAXN][MAXN];

int main() {
  int t; cin >> t;
  for(int tc = 1; tc <= t; tc++) {
    int n, r; cin >> n >> r;

    memset(dist, 0x3f, sizeof(dist));
    while(r--) {
      int a, b; cin >> a >> b;
      dist[a][b] = dist[b][a] = 1;
    }

    int st, end; cin >> st >> end;
    dist[st][st] = dist[end][end] = 0;

    for(int k = 0; k < n; k++) {
      for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }

    int maxTime = 0;
    for(int i = 0; i < n; i++)
      maxTime = max(maxTime, dist[st][i] + dist[i][end]);
    cout << "Case " << tc << ": " << maxTime << endl;
  }
  return 0;
}
