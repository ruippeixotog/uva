#include <algorithm>
#include <cstring>
#include <iostream>
#include <set>

#define siterator set<int>::iterator

#define MAXN 30
#define MAXT 1000

using namespace std;

int depth[MAXN], value[MAXN];
int dp[MAXT + 1];
bool selected[MAXN][MAXT + 1];

int main() {
  int ds = 0, t, w, n;
  while(cin >> t >> w >> n) {
    if(ds++) cout << endl;

    for(int i = 0; i < n; i++)
      cin >> depth[i] >> value[i];

    memset(dp, -1, (t + 1) * sizeof(int));
    memset(selected, false, sizeof(selected));
    dp[0] = 0;

    set<int> treasures;
    int maxt = 0, best = 0, freeValue = 0;
    
    for(int k = 0; k < n; k++) {
      int cost = 3 * w * depth[k];
      if(cost == 0) {
        treasures.insert(k);
        freeValue += value[k];
        continue;
      }
      for(int i = maxt; i >= 0; i--) {
        if(dp[i] != -1 && i + cost <= t && dp[i] + value[k] > dp[i + cost]) {
          dp[i + cost] = dp[i] + value[k];
          selected[k][i + cost] = true;

          if(dp[i + cost] > dp[best]) best = i + cost;
          maxt = max(maxt, i + cost);
        }
      }
    }

    cout << (dp[best] + freeValue) << endl;
    for(int k = n - 1; k >= 0 && best > 0; k--) {
      if(selected[k][best]) {
        treasures.insert(k);
        best -= 3 * w * depth[k];
      }
    }
    cout << treasures.size() << endl;
    for(siterator it = treasures.begin(); it != treasures.end(); it++)
      cout << depth[*it] << " " << value[*it] << endl;
  }
  return 0;
}