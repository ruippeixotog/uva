#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>

#define MAXN 100

using namespace std;

map<string, int> nameIndex;
string names[MAXN];

vector<int> graph[MAXN];

int dfsCount, dfsNumber[MAXN], dfsLow[MAXN];
vector<string> criticals;

void dfs(int k, int parent) {
  dfsNumber[k] = dfsLow[k] = ++dfsCount;

  bool isCrit = false; int numChildren = 0;
  for(int i = 0; i < (int) graph[k].size(); i++) {
    if(!dfsNumber[graph[k][i]]) {
      numChildren++;
      dfs(graph[k][i], k);
      if(dfsLow[graph[k][i]] >= dfsNumber[k]) isCrit = true;
      dfsLow[k] = min(dfsLow[k], dfsLow[graph[k][i]]);
    }
    else if(graph[k][i] != parent)
      dfsLow[k] = min(dfsLow[k], dfsNumber[graph[k][i]]);
  }
  if(parent == -1) isCrit = (numChildren > 1);
  if(isCrit) criticals.push_back(names[k]);
}

int main() {
  int n, tc = 0;
  while(cin >> n && n > 0) {
    if(tc) cout << endl;

    nameIndex.clear();
    for(int i = 0; i < n; i++) {
      string name; cin >> name;
      nameIndex[name] = i; names[i] = name;
    }

    for(int i = 0; i < n; i++) graph[i].clear();
    int r; cin >> r;
    while(r--) {
      string left, right; cin >> left >> right;
      graph[nameIndex[left]].push_back(nameIndex[right]);
      graph[nameIndex[right]].push_back(nameIndex[left]);
    }

    dfsCount = 0;
    memset(dfsNumber, 0, sizeof(dfsNumber));
    criticals.clear();
    for(int i = 0; i < n; i++) dfs(i, -1);

    sort(criticals.begin(), criticals.end());

    printf("City map #%d: %d camera(s) found\n", ++tc, criticals.size());
    for(int i = 0; i < (int) criticals.size(); i++)
      cout << criticals[i] << endl;
  }
  return 0;
}
