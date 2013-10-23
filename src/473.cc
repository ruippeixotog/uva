#include <algorithm>
#include <cstring>
#include <iostream>

#define MAXN 800
#define MAXT 100
#define MAXM 100

using namespace std;

int length[MAXN];
int dp[MAXM * MAXT + 1];

int main() {
  int t; cin >> t;
  for(int tc = 0; tc < t; tc++) {
    if(tc) cout << endl;

    int n, t, m; cin >> n >> t >> m;
    for(int i = 0; i < n; i++) {
      cin >> length[i]; cin.ignore(1);
    }

    memset(dp, -1, (m * t + 1) * sizeof(int));
    dp[0] = 0;

    for(int i = 0; i < n; i++) {
      for(int j = m * t - length[i]; j >= 0; j--) {
        if(dp[j] != -1) {
          int disc = j / t;
          int next = disc == (j + length[i] - 1) / t ?
            j + length[i] : (disc + 1) * t + length[i];

          dp[next] = max(dp[next], dp[j] + 1);
        }
      }
    }
    for(int j = 1; j <= m * t; j++)
      dp[j] = max(dp[j], dp[j - 1]);

    cout << dp[m * t] << endl;
  }
  return 0;
}
