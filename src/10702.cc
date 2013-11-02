#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

#define MAXC 100
#define MAXT 1000

int profit[MAXC][MAXC];
vector<int> end;

int dp[MAXT + 1][MAXC];

int main() {
  int c, s, e, t;
  while(cin >> c >> s >> e >> t && c > 0) {
    for(int i = 0; i < c; i++) {
      for(int j = 0; j < c; j++) {
        cin >> profit[i][j];
      }
    }

    end.resize(e);
    for(int i = 0; i < e; i++) {
      int ei; cin >> ei; end[i] = ei - 1;
    }

    memset(dp, -1, sizeof dp);
    dp[0][s - 1] = 0;

    for(int i = 0; i < t; i++) {
      for(int j = 0; j < c; j++) {
        if(dp[i][j] == -1) continue;

        for(int k = 0; k < c; k++)
          dp[i + 1][k] = max(dp[i + 1][k], dp[i][j] + profit[j][k]);
      }
    }

    int totalMax = -1;
    for(int i = 0; i < e; i++)
      totalMax = max(totalMax, dp[t][end[i]]);
    cout << totalMax << endl;
  }
  return 0;
}
