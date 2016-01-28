#include <algorithm>
#include <cstring>
#include <iostream>
#include <utility>
#include <vector>

#define ll long long

#define MAXN (100 + 1)
#define INF 1e9

using namespace std;

int n, d, k;
vector<int> adjs[MAXN];
ll cost[MAXN][MAXN], cap[MAXN][MAXN];

ll dist[MAXN]; int parent[MAXN];  // shortest path
ll flow[MAXN][MAXN];              // mcmf

ll bellmanFord(int src, int dest) {
  memset(dist, 0x3f, sizeof(dist));
  memset(parent, -1, sizeof(parent));
  dist[src] = 0;

  for(int k = 0; k <= n; k++) {
    for(int i = 0; i <= n; i++) {
      for(int j = 0; j < adjs[i].size(); j++) {
        int adj = adjs[i][j];

        if(flow[i][adj] < cap[i][adj] && dist[i] + cost[i][adj] < dist[adj]) {
          dist[adj] = dist[i] + cost[i][adj];
          parent[adj] = i;
        }

        if(flow[adj][i] && dist[i] - cost[adj][i] < dist[adj]) {
          dist[adj] = dist[i] - cost[adj][i];
          parent[adj] = i;
        }
      }
    }
  }
  return dist[dest];
}

pair<ll, ll> mcmf(int src, int sink) {
  memset(flow, 0, sizeof(flow));

  ll minCost = 0, maxFlow = 0;
  while(bellmanFord(src, sink) < INF) {
    ll bot = INF;

    for(int v = sink, u = parent[v]; v != src; u = parent[v = u]) {
      bot = min(bot, flow[v][u] ? flow[v][u] : cap[u][v] - flow[u][v]);
    }

    for(int v = sink, u = parent[v]; v != src; u = parent[v = u]) {
      if(flow[v][u]) { flow[v][u] -= bot; minCost -= bot * cost[v][u]; }
      else { flow[u][v] += bot; minCost += bot * cost[u][v]; }
    }
    maxFlow += bot;
  }
  return make_pair(minCost, maxFlow);
}

int main() {
  int m;
  while(cin >> n >> m) {
    for(int i = 0; i <= n; i++)
      adjs[i].clear();

    for(int i = 0; i < m; i++) {
      int a, b, pt; cin >> a >> b >> pt;
      adjs[a].push_back(b);
      adjs[b].push_back(a);
      cost[a][b] = cost[b][a] = pt;
    }

    cin >> d >> k;
    for(int i = 1; i <= n; i++) {
      for(int j = i + 1; j <= n; j++) {
        cap[i][j] = cap[j][i] = k;
      }
    }

    adjs[0].push_back(1);
    cap[0][1] = d;

    pair<ll, ll> res = mcmf(0, n);
    if(res.second < d) cout << "Impossible." << endl;
    else cout << res.first << endl;
  }
  return 0;
}
