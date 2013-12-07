#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define MAXN 100 

using namespace std;

vector<int> adjs[MAXN];
int graph[MAXN][MAXN];

int prev[MAXN], minEdge[MAXN];

int main() {
  int n, tc = 0;
  while(cin >> n && n > 0) {
    int s, t, c; cin >> s >> t >> c;
    --s; --t; 

    for(int i = 0; i < n; i++) adjs[i].clear();
    memset(graph, 0, sizeof(graph));

    while(c--) {
      int ca, cb, cc; cin >> ca >> cb >> cc;
      adjs[--ca].push_back(--cb);
      adjs[cb].push_back(ca);
      graph[ca][cb] = graph[cb][ca] += cc;
    }

    int f = 0;
    while(true) {
      memset(prev, -1, sizeof(prev));
      memset(minEdge, 0x3f, sizeof(minEdge));
      queue<int> q; q.push(s);

      while(!q.empty()) {
        int curr = q.front(); q.pop();
        if(curr == t) break;
        for(int i = 0; i < (int) adjs[curr].size(); i++) {
          int adj = adjs[curr][i];
          if(prev[adj] < 0 && graph[curr][adj] > 0) {
            prev[adj] = curr;
            minEdge[adj] = min(minEdge[curr], graph[curr][adj]);
            q.push(adj);
          }
        }
      }
      if(prev[t] == -1) break;
      f += minEdge[t];

      int curr = t, next;
      while(curr != s) {
        next = curr; curr = prev[next];
        graph[curr][next] -= minEdge[t];
        graph[next][curr] += minEdge[t];
      }
    }

    cout << "Network " << (++tc) << endl;
    cout << "The bandwidth is " << f << "." << endl << endl;
  }
  return 0;
}
