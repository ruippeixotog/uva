#include <algorithm>
#include <cstring>
#include <iostream>

#define MAXN 1000
#define MAXW 30

using namespace std;

int value[MAXN], weight[MAXN];
int dp[MAXW + 1];

int main() {
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    for(int i = 0; i < n; i++)
      cin >> value[i] >> weight[i];

    memset(dp, -1, sizeof(dp));
    dp[0] = 0;

    for(int i = 0; i < n; i++) {
      for(int j = MAXW - weight[i]; j >= 0; j--) {
        if(dp[j] != -1)
          dp[j + weight[i]] = max(
            dp[j + weight[i]], dp[j] + value[i]);
      }
    }
    for(int j = 1; j <= MAXW; j++)
      dp[j] = max(dp[j], dp[j - 1]);

    int g; cin >> g;
    int mw, total = 0;
    while(g--) { cin >> mw; total += dp[mw]; }
    cout << total << endl;
  }
  return 0;
}
