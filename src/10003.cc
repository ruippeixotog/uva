#include <algorithm>
#include <iostream>

#define MAXN 49
#define INFC 60000

using namespace std;

int cuts[MAXN];
int dp[MAXN + 1][MAXN + 1];

int main() {
  int l;
  while(cin >> l && l > 0) {
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> cuts[i];

    for(int i = 0; i < n; i++) dp[i][i] = 0;

    for(int nCuts = 1; nCuts <= n + 1; nCuts++) {
      for(int i = 0; i <= n - nCuts; i++) {
        int j = i + nCuts;
        int len = (j == n ? l : cuts[j]) - (i == 0 ? 0 : cuts[i - 1]);

        int best = INFC;
        for(int k = i; k < j; k++)
          best = min(best, len + dp[i][k] + dp[k + 1][j]);

        dp[i][j] = best;
      }
    }
    cout << "The minimum cutting is " << dp[0][n] << "." << endl;
  }
  return 0;
}
