#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

#define MAXN 26
#define MAXM 30

int zero[MAXN], one[MAXN];
vector<int> winners;

int dp[MAXM + 1][MAXN];

int main() {
  int n;
  while(cin >> n) {
    
    winners.clear();
    for(int i = 0; i < n; i++) {
      char lbl, l0, l1, sp;
      cin >> lbl >> l0 >> l1 >> sp;
      zero[i] = l0 - 'A'; one[i] = l1 - 'A';
      if(sp == 'x') winners.push_back(i);
    }
    int m; cin >> m;

    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;

    for(int i = 0; i < m; i++) {
      for(int j = 0; j < n; j++) {
        dp[i + 1][zero[j]] += dp[i][j];
        dp[i + 1][one[j]] += dp[i][j];
      }
    }

    int total = 0;
    for(int i = 0; i < (int) winners.size(); i++)
      total += dp[m][winners[i]];
    cout << total << endl;
  }
  return 0;
}