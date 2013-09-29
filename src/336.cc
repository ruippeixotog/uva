#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <vector>

#define uint unsigned int

#define MAXN 30

using namespace std;

map<int, vector<int> > graph;
set<int> visited;

int bfs(int st, int ttl) {
  visited.clear();
  visited.insert(st);

  queue< pair<int, int> > q;
  q.push(pair<int, int>(st, ttl));

  int reachable = 0;

  while(!q.empty()) {
    pair<int, int> node = q.front();
    q.pop();
    reachable++;

    for(uint i = 0; i < graph[node.first].size(); i++) {
      int adj = graph[node.first][i];
      if(!visited.count(adj) && node.second > 0) {
        visited.insert(adj);
        q.push(pair<int, int>(adj, node.second - 1));
      }
    }
  }
  return reachable;
}  

int main() {
  int nc, q = 0;
  while(scanf("%d", &nc) > 0 && nc > 0) {
    graph.clear();

    int n1, n2;
    while(nc--) {
      scanf("%d %d", &n1, &n2);
      graph[n1].push_back(n2);
      graph[n2].push_back(n1);
    }

    while(scanf("%d %d", &n1, &n2) > 0 && n1 > 0) {
      int reachable = bfs(n1, n2);
      printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",
        ++q, graph.size() - reachable, n1, n2);
    }
  }
  return 0;
}