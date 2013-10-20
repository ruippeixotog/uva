#include <cstdio>
#include <cstring>
#include <vector>

#define ll long long

#define NCOINS 5
#define MAXN 30000

using namespace std;

ll dp[MAXN + 1];
int coins[] = {1, 5, 10, 25, 50};

int main() {
  int n;
  while(scanf("%d\n", &n) > 0) {
    memset(dp, 0, (n + 1) * sizeof(ll));
    dp[0] = 1;
    for(int k = 0; k < NCOINS; k++) {
      for(int i = 1; i <= n; i++) {
        if(i - coins[k] >= 0) dp[i] += dp[i - coins[k]];
      }
    }
    if(dp[n] == 1)
      printf("There is only 1 way to produce %d cents change.\n", n);
    else
      printf("There are %lld ways to produce %d cents change.\n", dp[n], n);
  }
  return 0;
}
