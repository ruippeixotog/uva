#include <cstring>
#include <iostream>
#include <vector>

#define MAXN 100000

using namespace std;

vector<int> graph[MAXN];

bool visited[MAXN];
vector<int> order;

void dfs(int k, bool topSort) {
  visited[k] = true;
  for(int i = 0; i < (int) graph[k].size(); i++) {
    if(!visited[graph[k][i]]) dfs(graph[k][i], topSort);
  }
  if(topSort) order.push_back(k);
}

int main() {
  int t; cin >> t;
  while(t--) {
    int n, m; cin >> n >> m;

    for(int i = 0; i < n; i++) graph[i].clear();
    while(m--) {
      int a, b; cin >> a >> b;
      graph[a - 1].push_back(b - 1);
    }

    order.clear();
    memset(visited, false, sizeof(visited));
    for(int i = 0; i < n; i++) {
      if(!visited[i]) dfs(i, true);
    }

    memset(visited, false, sizeof(visited));
    int count = 0;
    for(int i = n - 1; i >= 0; i--) {
      if(!visited[order[i]]) {
        dfs(order[i], false);
        count++;
      }
    }
    cout << count << endl;
  }
  return 0;
}
