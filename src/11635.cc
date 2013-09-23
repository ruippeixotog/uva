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
    // fprintf(stderr, "<- state (%d, %d)\n", -s.first, s.second);

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
        // fprintf(stderr, "-> state (%d, %d)\n", -(s.first - edge.second), edge.first);
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
      hid[--hotels[i]] = i + 1;
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
/*
    fprintf(stderr, "-- graph --\n");
    for(int i = 0; i < n; i++) {
      fprintf(stderr, "%d -> ", i);
      for(uint j = 0; j < graph[i].size(); j++)
        fprintf(stderr, "%d (%d), ", graph[i][j].first, graph[i][j].second);
      fprintf(stderr, "\n");
    }

    fprintf(stderr, "-- hids --\n");
    for(int i = 0; i < n; i++) {
      fprintf(stderr, "%d ", hid[i]);
    }
    fprintf(stderr, "\n");*/

    memset(dist, 0xFF, sizeof(dist));

    dijkstra(0, true);
    for(int i = 0; i < h; i++)
      dijkstra(hotels[i], true);
/*
    fprintf(stderr, "-- dists --\n");
    for(int i = 0; i < h + 2; i++) {
      for(int j = 0; j < h + 2; j++)
        fprintf(stderr, "%d ", dist[i][j]);
      fprintf(stderr, "\n");
    }*/

    transformGraph(h);
/*
    fprintf(stderr, "-- transformed graph --\n");
    for(int i = 0; i < h + 2; i++) {
      fprintf(stderr, "%d -> ", i);
      for(uint j = 0; j < graph[i].size(); j++)
        fprintf(stderr, "%d (%d), ", graph[i][j].first, graph[i][j].second);
      fprintf(stderr, "\n");
    }*/

    memset(dist, 0xFF, sizeof(dist));
    dijkstra(0, false);
/*
    fprintf(stderr, "-- transformed dists --\n");
    for(int i = 0; i < h + 2; i++) {
      for(int j = 0; j < h + 2; j++)
        fprintf(stderr, "%d ", dist[i][j]);
      fprintf(stderr, "\n");
    }*/

    printf("%d\n", max(-1, dist[0][h + 1] - 1));
  }
  return 0;
}
