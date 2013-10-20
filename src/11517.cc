#include <climits>
#include <cstring>
#include <iostream>

#define MAXS 10000

using namespace std;

int dp[2 * MAXS];

int main() {
  int t; cin >> t;
  while(t--) {
    int s, n; cin >> s >> n;

    memset(dp, -1, 2 * s * sizeof(int));
    dp[0] = 0;

    int best = INT_MAX;
    for(int k = 0; k < n; k++) {
      int value; cin >> value;

      for(int i = s - 1; i >= 0; i--) {
        if(dp[i] != -1) {
          if(dp[i + value] == -1) dp[i + value] = dp[i] + 1;
          else dp[i + value] = min(dp[i + value], dp[i] + 1);

          if(i + value >= s)
            best = min(best, i + value);
        }
      }
    }
    cout << best << " " << dp[best] << endl;
  }
  return 0;
}
