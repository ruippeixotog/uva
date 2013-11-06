#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

#define MAXN 1000

using namespace std;

vector<int> graph[MAXN];

int dfsCount, dfsNumber[MAXN], dfsLow[MAXN];
vector<pair<int, int> > criticals;

void dfs(int k, int parent) {
  dfsNumber[k] = dfsLow[k] = ++dfsCount;

  int numChildren = 0;
  for(int i = 0; i < (int) graph[k].size(); i++) {
    if(!dfsNumber[graph[k][i]]) {
      numChildren++;
      dfs(graph[k][i], k);
      if(dfsLow[graph[k][i]] > dfsNumber[k]) {
        criticals.push_back(pair<int, int>(
          min(k, graph[k][i]), max(k, graph[k][i])));
      }
      dfsLow[k] = min(dfsLow[k], dfsLow[graph[k][i]]);
    }
    else if(graph[k][i] != parent)
      dfsLow[k] = min(dfsLow[k], dfsNumber[graph[k][i]]);
  }
}

int main() {
  int n, k, nadj, adj;
  while(cin >> n) {
    for(int i = 0; i < n; i++) graph[i].clear();

    for(int i = 0; i < n; i++) {
      scanf("%d (%d)", &k, &nadj);
      while(nadj--) {
        cin >> adj;
        graph[k].push_back(adj);
        graph[adj].push_back(k);
      }
    }

    dfsCount = 0;
    memset(dfsNumber, 0, sizeof(dfsNumber));
    criticals.clear();
    for(int i = 0; i < n; i++) dfs(i, -1);

    sort(criticals.begin(), criticals.end());

    cout << criticals.size() << " critical links" << endl;
    for(int i = 0; i < (int) criticals.size(); i++)
      cout << criticals[i].first << " - " << criticals[i].second << endl;
    cout << endl;
  }
  return 0;
}
