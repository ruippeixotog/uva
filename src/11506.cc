#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define MAXM 50
#define MAXGM (MAXM * 2)

#define INF 0x3f3f3f3f

using namespace std;

int m;
vector<int> adjs[MAXGM];
int graph[MAXGM][MAXGM];

int prev[MAXGM], minEdge[MAXGM];
bool cutSet[MAXGM];

inline int out(int i) { return i + m; }

void dfsCutSet(int curr) {
  if(cutSet[curr]) return;

  cutSet[curr] = true;
  for(int i = 0; i < (int) adjs[curr].size(); i++) {
    int adj = adjs[curr][i];
    if(graph[curr][adj] > 0) dfsCutSet(adj);
  }
}

int main() {
  int w;
  while(cin >> m >> w && m > 0) {
    int gm = 2 * m;
    for(int i = 0; i < gm; i++) adjs[i].clear();
    memset(graph, 0, sizeof(graph));

    int src = 0, sink = m - 1;
    graph[src][out(src)] = graph[sink][out(sink)] = INF;
    adjs[src].push_back(out(src));
    adjs[sink].push_back(out(sink));

    for(int i = 0; i < m - 2; i++) {
      int a, c; cin >> a >> c;
      a--;
      graph[a][out(a)] = c;
      adjs[a].push_back(out(a));
    }

    while(w--) {
      int a, b, c; cin >> a >> b >> c;
      a--; b--;
      adjs[out(a)].push_back(b);
      adjs[out(b)].push_back(a);
      graph[out(a)][b] = graph[out(b)][a] = c;
    }

    while(true) {
      memset(prev, -1, sizeof(prev));
      memset(minEdge, 0x3f, sizeof(minEdge));
      queue<int> q; q.push(src);

      while(!q.empty()) {
        int curr = q.front(); q.pop();
        if(curr == sink) break;

        for(int i = 0; i < (int) adjs[curr].size(); i++) {
          int adj = adjs[curr][i];
          if(prev[adj] < 0 && graph[curr][adj] > 0) {
            prev[adj] = curr;
            minEdge[adj] = min(minEdge[curr], graph[curr][adj]);
            q.push(adj);
          }
        }
      }
      if(prev[sink] == -1) break;

      int curr = sink, next;
      while(curr != src) {
        next = curr; curr = prev[next];
        graph[curr][next] -= minEdge[sink];
        graph[next][curr] += minEdge[sink];
      }
    }

    memset(cutSet, false, sizeof(cutSet));
    dfsCutSet(src);

    int cost = 0;
    for(int i = 0; i < gm; i++) {
      if(!cutSet[i]) continue;

      for(int j = 0; j < (int) adjs[i].size(); j++) {
        int adj = adjs[i][j];
        if(!cutSet[adj] && graph[i][adj] == 0 && graph[adj][i] > 0)
          cost += graph[adj][i];
      }
    }
    cout << cost << endl;
  }
  return 0;
}
