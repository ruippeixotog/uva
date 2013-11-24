#include <cstring>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

#define MAXN 1000

using namespace std;

vector<int> graph[MAXN];
int roomEnergy[MAXN], maxEnergy[MAXN];

bool found[MAXN];

int main() {
  int n;
  while(cin >> n && n >= 0) {
    for(int i = 0; i < n; i++) {
      int nd; cin >> roomEnergy[i] >> nd;
      graph[i].clear();
      while(nd--) {
        int d; cin >> d;
        graph[i].push_back(--d);
      }
    }

    memset(maxEnergy, 0, sizeof(maxEnergy));
    maxEnergy[0] = 100;

    queue<int> posCycle;
    for(int k = 0; k <= n; k++) {
      for(int i = 0; i < n; i++) {
        if(maxEnergy[i] <= 0) continue;
        for(int j = 0; j < (int) graph[i].size(); j++) {
          int newEn = maxEnergy[i] + roomEnergy[graph[i][j]];
          if(newEn > maxEnergy[graph[i][j]]) {
            maxEnergy[graph[i][j]] = newEn;
            if(k == n) posCycle.push(graph[i][j]);
          }
        }
      }
    }

    memset(found, false, sizeof(found));
    bool infiniteEn = false;
    while(!posCycle.empty()) {
      int r = posCycle.front(); posCycle.pop();
      if(r == n - 1) { infiniteEn = true; break; }

      for(int j = 0; j < (int) graph[r].size(); j++) {
        if(!found[graph[r][j]]) {
          found[graph[r][j]] = true;
          posCycle.push(graph[r][j]);
        }
      }
    }

    cout << ((maxEnergy[n - 1] > 0) | infiniteEn ?
      "winnable" : "hopeless") << endl;
  }
  return 0;
}
