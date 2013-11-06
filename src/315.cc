#include <algorithm>
#include <cstring>
#include <iostream>
#include <sstream>
#include <vector>

#define MAXN 99

using namespace std;

vector<int> graph[MAXN];

int dfsCount, dfsNumber[MAXN], dfsLow[MAXN];

int dfs(int k, int parent) {
  dfsNumber[k] = dfsLow[k] = ++dfsCount;

  int numCrits = 0, numChildren = 0;
  bool isCrit = false;
  for(int i = 0; i < (int) graph[k].size(); i++) {
    if(!dfsNumber[graph[k][i]]) {
      numChildren++;
      numCrits += dfs(graph[k][i], k);
      if(dfsLow[graph[k][i]] >= dfsNumber[k]) isCrit = true;
      dfsLow[k] = min(dfsLow[k], dfsLow[graph[k][i]]);
    }
    else if(graph[k][i] != parent)
      dfsLow[k] = min(dfsLow[k], dfsNumber[graph[k][i]]);
  }
  if(parent == -1) isCrit = (numChildren > 1);
  return numCrits + isCrit;
}

int main() {
  int n, k, adj;
  while(cin >> n && n > 0) {
    for(int i = 0; i < n; i++) graph[i].clear();

    while(cin >> k && k > 0) {
      string line; getline(cin, line);
      stringstream sin(line);
      while(sin >> adj) {
        graph[k - 1].push_back(adj - 1);
        graph[adj - 1].push_back(k - 1);
      }
    }

    dfsCount = 0;
    memset(dfsNumber, 0, sizeof(dfsNumber));
    cout << dfs(0, -1) << endl;
  }
  return 0;
}
