#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

#define MAXN 1000

vector<int> adjs[MAXN];

int dp[MAXN][2];

int minExits(int node, int parent, bool parExit) {
  if(dp[node][parExit] >= 0) return dp[node][parExit];

  int best = 1;
  for(int i = 0; i < (int) adjs[node].size(); i++) {
    if(adjs[node][i] != parent)
      best += minExits(adjs[node][i], node, true);
  }

  if(parent == -1 || parExit) {
    int other = 0;
    for(int i = 0; i < (int) adjs[node].size(); i++) {
      if(adjs[node][i] != parent)
        other += minExits(adjs[node][i], node, false);
    }
    best = min(best, other); 
  }

  return dp[node][parExit] = best;
}

int main() {
  int n;
  while(cin >> n && n > 0) {
    for(int i = 0; i < n; i++) {
      int ni, adj; cin >> ni;
      adjs[i].resize(ni);
      for(int j = 0; j < ni; j++) {
        cin >> adj; adjs[i][j] = adj - 1;
      }
    }
    memset(dp, -1, sizeof dp);
    cout << max(1, minExits(0, -1, true)) << endl;
  }
  return 0;
}
