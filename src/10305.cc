#include <cstring>
#include <iostream>
#include <vector>

#define MAXN 100

using namespace std;

vector<int> graph[MAXN];

bool visited[MAXN];
vector<int> order;

void topologicalSort(int k) {
  if(visited[k]) return;
  visited[k] = true;

  for(int i = 0; i < (int) graph[k].size(); i++)
    topologicalSort(graph[k][i]);
  order.push_back(k);
}

int main() {
  int n, m;
  while(cin >> n >> m && n > 0) {
    for(int i = 0; i < n; i++) graph[n].clear();
    while(m--) {
      int a, b; cin >> a >> b;
      graph[a - 1].push_back(b - 1);
    }

    memset(visited, false, sizeof(visited));
    order.clear();
    for(int i = 0; i < n; i++) topologicalSort(i);

    cout << (order[n - 1] + 1);
    for(int i = n - 2; i >= 0; i--) cout << " " << (order[i] + 1);
    cout << endl;
  }
  return 0;
}
