#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

#define MAXN 10
#define MAXK 1000

vector<int> flights[MAXN][MAXN];

int dp[MAXK + 1][MAXN];

int main() {
  int n, k, tc = 0;
  while(cin >> n >> k && n > 0) {
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        if(i == j) continue;
        flights[i][j].clear();
        int d, di; cin >> d;
        while(d--) { cin >> di; flights[i][j].push_back(di); }
      }
    }

    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;

    for(int i = 0; i < k; i++) {
      for(int j = 0; j < n; j++) {
        for(int m = 0; m < n; m++) {
          if(j == m) continue;
          int day = i % flights[j][m].size();
          int cost = flights[j][m][day];
          if(cost)
            dp[i + 1][m] = min(dp[i + 1][m], dp[i][j] + cost);
        }
      }
    }

    printf("Scenario #%d\n", ++tc);
    if(dp[k][n - 1] == 0x3f3f3f3f) printf("No flight possible.\n\n");
    else printf("The best flight costs %d.\n\n", dp[k][n - 1]);
  }
  return 0;
}