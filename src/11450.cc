#include <algorithm>
#include <cstdio>
#include <cstring>

#define MMAX 200
#define CMAX 20

using namespace std;

int dp[CMAX + 1][MMAX];

int main() {
  int n;
  scanf("%d\n", &n);

  while(n--) {
    int m, c, k, p;
    scanf("%d %d\n", &m, &c);

    memset(dp, 0xFF, sizeof(dp));
    memset(dp, 0, sizeof(dp[0]));

    for(int i = 0; i < c; i++) {
      scanf("%d", &k);

      for(int j = 0; j < k; j++) {
        scanf("%d", &p);

        for(int l = 1; l <= m; l++) {
          dp[i + 1][l] = max(dp[i + 1][l], dp[i + 1][l - 1]);
          if(l - p >= 0 && dp[i][l - p] >= 0)
            dp[i + 1][l] = max(dp[i + 1][l], dp[i][l - p] + p);
        }
      }
    }
    if(dp[c][m] == -1) printf("no solution\n");
    else printf("%d\n", dp[c][m]);
  }
  return 0;
}
