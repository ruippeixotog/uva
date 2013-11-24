#include <cstring>
#include <iostream>
#include <utility>
#include <vector>

#define MAXN 1000

using namespace std;

vector<int> graph[MAXN];
int roomEnergy[MAXN];
int maxEnergy[MAXN];

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
      maxEnergy[i] = -1e9;
    }

    maxEnergy[0] = 100;
    bool improved = false;
    for(int k = 0; k <= n; k++) {
      improved = false;
      for(int i = 0; i < n; i++) {
        if(maxEnergy[i] <= 0) continue;
        for(int j = 0; j < (int) graph[i].size(); j++) {
          int newEn = maxEnergy[i] + roomEnergy[graph[i][j]];
          if(newEn > maxEnergy[graph[i][j]]) {
            if(graph[i][j] == n - 1) improved = true;
            maxEnergy[graph[i][j]] = newEn;
          }
        }
      }
    }
    cout << ((maxEnergy[n - 1] > 0) | improved ?
      "winnable" : "hopeless") << endl;
  }
  return 0;
}
