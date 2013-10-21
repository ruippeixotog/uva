#include <algorithm>
#include <cstring>
#include <iostream>

#define MAXM 100
#define MAXV 500

using namespace std;

int coins[MAXM];
bool dp[MAXV * MAXM / 2 + 1];

int main() {
  int t; cin >> t;
  while(t--) {
    int m; cin >> m;
    int total = 0;
    for(int i = 0; i < m; i++) {
      cin >> coins[i];
      total += coins[i];
    }
    int half = total / 2;
    memset(dp, false, (half + 1) * sizeof(bool));
    dp[0] = true;

    int best = 0;
    for(int k = 0; k < m; k++) {
      for(int i = best; i >= 0; i--) {
        if(i + coins[k] <= half) {
          dp[i + coins[k]] = dp[i + coins[k]] || dp[i];
          if(dp[i + coins[k]])
            best = max(best, i + coins[k]);
        }
      }
    }
    cout << (total - best) - best << endl;  
  }
  return 0;
}