#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define MAXN 50 

using namespace std;

vector<int> adjs[MAXN];
int graph[MAXN][MAXN];

int prev[MAXN], minEdge[MAXN];
bool cutSet[MAXN];

int main() {
  int n, m;
  while(cin >> n >> m && n > 0) {
    for(int i = 0; i < n; i++) adjs[i].clear();
    memset(graph, 0, sizeof(graph));

    while(m--) {
      int a, b, c; cin >> a >> b >> c;
      adjs[--a].push_back(--b);
      adjs[b].push_back(a);
      graph[a][b] = graph[b][a] = c;
    }

    while(true) {
      memset(prev, -1, sizeof(prev));
      memset(minEdge, 0x3f, sizeof(minEdge));
      queue<int> q; q.push(0);

      while(!q.empty()) {
        int curr = q.front(); q.pop();
        if(curr == 1) break;
        for(int i = 0; i < (int) adjs[curr].size(); i++) {
          int adj = adjs[curr][i];
          if(prev[adj] < 0 && graph[curr][adj] > 0) {
            prev[adj] = curr;
            minEdge[adj] = min(minEdge[curr], graph[curr][adj]);
            q.push(adj);
          }
        }
      }
      if(prev[1] == -1) break;

      int curr = 1, next;
      while(curr) {
        next = curr; curr = prev[next];
        graph[curr][next] -= minEdge[1];
        graph[next][curr] += minEdge[1];
      }
    }

    for(int i = 0; i < n; i++) {
      for(int j = i + 1; j < n; j++) {
        if((prev[i] < 0) != (prev[j] < 0) &&
          (graph[i][j] == 0) != (graph[j][i] == 0)) {
          cout << (i + 1) << " " << (j + 1) << endl;
        }
      }
    }
    cout << endl;
  }
  return 0;
}
