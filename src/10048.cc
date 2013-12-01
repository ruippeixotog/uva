#include <cstring>
#include <iostream>

#define MAXC 100
#define INF 0x3f3f3f3f

using namespace std;

int graph[MAXC][MAXC];

int main() {
  int c, s, q, tc = 0;
  while(cin >> c >> s >> q && (c > 0 || s > 0 || q >> 0)) {
    memset(graph, 0x3f, sizeof(graph));

    while(s--) {
      int c1, c2, d; cin >> c1 >> c2 >> d;
      graph[c1 - 1][c2 - 1] = graph[c2 - 1][c1 - 1] = d;
    }

    for(int k = 0; k < c; k++) {
      for(int i = 0; i < c; i++) {
        for(int j = 0; j < c; j++) {
          graph[i][j] = min(graph[i][j], max(graph[i][k], graph[k][j]));
        }
      }
    }

    if(tc) cout << endl;
    cout << "Case #" << (++tc) << endl;
    while(q--) {
      int c1, c2; cin >> c1 >> c2;
      if(graph[--c1][--c2] == INF) cout << "no path" << endl;
      else cout << graph[c1][c2] << endl;
    }
  }
  return 0;
}
