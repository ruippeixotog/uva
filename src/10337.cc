#include <algorithm>
#include <iostream>

#define MAXX 1000
#define MAXA 10

#define INF 1e8

using namespace std;

int wind[MAXX][MAXA];
int dp[MAXX + 1][MAXA];

int main() {
  int t; cin >> t;
  while(t--) {
    int x; cin >> x; x /= 100;
    for(int i = MAXA - 1; i >= 0; i--) {
      for(int j = 0; j < x; j++) cin >> wind[j][i];
    }

    dp[0][0] = 0;
    for(int i = 1; i < MAXA; i++) dp[0][i] = INF;

    for(int i = 1; i <= x; i++) {
      for(int j = 0; j < MAXA; j++) {
        dp[i][j] = dp[i - 1][j] + 30 - wind[i - 1][j];
        if(j > 0) dp[i][j] =
          min(dp[i][j], dp[i - 1][j - 1] + 60 - wind[i - 1][j - 1]);
        if(j < MAXA - 1) dp[i][j] =
          min(dp[i][j], dp[i - 1][j + 1] + 20 - wind[i - 1][j + 1]);
      }
    }
    cout << dp[x][0] << endl << endl;
  }
  return 0;
}
