#include <climits>
#include <iostream>

#define MAXM 40
#define MAXS 300

using namespace std;

int cvalue[MAXM], itvalue[MAXM], dp[MAXS + 1][MAXS + 1];

int main() {
  int n; cin >> n;
  while(n--) {
    int m, s; cin >> m >> s;

    for(int i = 0; i < m; i++)
      cin >> cvalue[i] >> itvalue[i];

    int target = s * s;
    int best = INT_MAX - 1;
    for(int i = 0; i <= s; i++) {
      for(int j = 0; i * i + j * j <= target; j++) {
        dp[i][j] = i == 0 && j == 0 ? 0 : INT_MAX - 1;
        for(int k = 0; k < m; k++) {
          if(i - cvalue[k] >= 0 && j - itvalue[k] >= 0)
            dp[i][j] = min(dp[i][j], dp[i - cvalue[k]][j - itvalue[k]] + 1);
        }
        if(i * i + j * j == target)
          best = min(best, dp[i][j]);
      }
    }
    if(best == INT_MAX - 1) cout << "not possible" << endl;
    else cout << best << endl;
  }
  return 0;
}
