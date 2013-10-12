#include <cstring>
#include <iostream>
#include <vector>

#define uint unsigned int

#define MAXN 100

using namespace std;

vector<int> graph[MAXN];

int blackAdj[MAXN];
vector<int> best, curr;

void colorNode(int n, int k) {
  if(k == n) {
    if(curr.size() > best.size()) best = curr;
    return;
  }
  if(blackAdj[k] == 0) {
    curr.push_back(k);
    for(uint i = 0; i < graph[k].size(); i++)
      blackAdj[graph[k][i]]++;

    colorNode(n, k + 1);

    for(uint i = 0; i < graph[k].size(); i++)
      blackAdj[graph[k][i]]--;
    curr.pop_back();
  }
  colorNode(n, k + 1);
}

int main() {
  int m; cin >> m;
  while(m--) {
    int n, k; cin >> n >> k;
    for(int i = 0; i < n; i++) graph[i].clear();
    while(k--) {
      int a, b; cin >> a >> b;
      graph[a - 1].push_back(b - 1);
      graph[b - 1].push_back(a - 1);
    }

    memset(blackAdj, 0, n * sizeof(int));
    curr.clear(); best.clear();
    colorNode(n, 0);

    cout << best.size() << endl;

    cout << (best[0] + 1);
    for(uint i = 1; i < best.size(); i++)
      cout << " " << (best[i] + 1);
    cout << endl;
  }
  return 0;
}