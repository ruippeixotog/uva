#include <cstring>
#include <iostream>
#include <vector>

#define MAXN 200

using namespace std;

vector<int> graph[MAXN];
int color[MAXN];

bool dfs(int k, int c) {
  if(color[k]) return color[k] == c;
  color[k] = c;
  for(int i = 0; i < (int) graph[k].size(); i++)
    if(!dfs(graph[k][i], -c)) return false;
  return true;
}

int main() {
  int n, l;
  while(cin >> n >> l && n > 0) {
    for(int i = 0; i < n; i++) graph[i].clear();
    while(l--) {
      int a, b; cin >> a >> b;
      graph[a].push_back(b);
      graph[b].push_back(a);
    }
    memset(color, 0, sizeof(color));
    bool poss = true;
    for(int i = 0; i < n; i++) {
      if(!color[i]) {
        poss &= dfs(i, 1);
        if(!poss) break;
      }
    }
    cout << (poss ? "" : "NOT ") << "BICOLORABLE." << endl;
  }
  return 0;
}
