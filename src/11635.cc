#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>

#define uint unsigned int

#define NMAX 10000
#define HMAX 100
#define MAXT 600

using namespace std;

vector< pair<int, int> > graph[NMAX];
int hotels[HMAX];
int hid[NMAX];

bool visited[NMAX];
int dist[HMAX + 2][HMAX + 2];

void dijkstra(int src, bool hidTransform) {
  int h = hid[src];
  memset(visited, 0, sizeof(visited));

  priority_queue<pair<int, int> > q;
  q.push(pair<int, int>(0, src));

  while(!q.empty()) {
    pair<int, int> s = q.top();
    q.pop();

    if(-s.first > MAXT) break;
    if(visited[s.second]) continue;

    visited[s.second] = true;
    if(hidTransform && hid[s.second] != -1)
      dist[h][hid[s.second]] = -s.first;
    else if(!hidTransform)
      dist[h][s.second] = -s.first;

    for(uint i = 0; i < graph[s.second].size(); i++) {
      pair<int, int> edge = graph[s.second][i];
      if(!visited[edge.first]) {
        q.push(pair<int, int>(s.first - edge.second, edge.first));
      }
    }
  }
}

void transformGraph(int h) {
  for(int i = 0; i < h + 2; i++) {
    graph[i].clear();
    for(int j = 0; j < h + 2; j++) {
      if(dist[i][j] > 0)
        graph[i].push_back(pair<int, int>(j, 1));
    }
  }
}

int main() {
  int n, h, m;
  while(scanf("%d\n", &n) > 0 && n > 0) {

    memset(hid, 0xFF, sizeof(hid));
    
    scanf("%d", &h);
    hid[0] = 0;
    hid[n - 1] = h + 1;
    for(int i = 0; i < h; i++) {
      scanf("%d", &hotels[i]);
      hotels[i]--;
      if(hotels[i] != 0 && hotels[i] != n - 1)
        hid[hotels[i]] = i + 1;
    }

    for(int i = 0; i < n; i++)
      graph[i].clear();

    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
      int a, b, t;
      scanf("%d %d %d\n", &a, &b, &t);
      graph[a - 1].push_back(pair<int, int>(b - 1, t));
      graph[b - 1].push_back(pair<int, int>(a - 1, t));
    }

    memset(dist, 0xFF, sizeof(dist));

    dijkstra(0, true);
    for(int i = 0; i < h; i++)
      dijkstra(hotels[i], true);

    transformGraph(h);

    memset(dist, 0xFF, sizeof(dist));
    dijkstra(0, false);

    printf("%d\n", max(-1, dist[0][h + 1] - 1));
  }
  return 0;
}
