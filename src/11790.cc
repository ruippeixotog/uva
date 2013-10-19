#include <iostream>
#include <vector>

using namespace std;

vector<int> height, length, dp;

int longestSubseq(int n, bool (*comp)(int, int)) {
  int max = 0;
  for(int i = 0; i < n; i++) {
    int best = 0;
    for(int j = 0; j < i; j++) {
      if(comp(height[j], height[i]) && dp[j] > best)
        best = dp[j];
    }
    dp[i] = best + length[i];
    if(dp[i] > max) max = dp[i];
  }
  return max;
}

bool lt(int a, int b) { return a < b; }
bool gt(int a, int b) { return a > b; }

int main() {
  int t; cin >> t;
  for(int u = 1; u <= t; u++) {
    int n, e; cin >> n;
    height.resize(n); length.resize(n);
    for(int i = 0; i < n; i++) { cin >> e; height[i] = e; }
    for(int i = 0; i < n; i++) { cin >> e; length[i] = e; }

    dp.resize(n);
    int incMax = longestSubseq(n, lt);
    int decMax = longestSubseq(n, gt);

    cout << "Case " << u << ". ";
    if(incMax >= decMax) cout << "Increasing (" << incMax <<
      "). Decreasing (" << decMax << ")." << endl;
    else cout << "Decreasing (" << decMax <<
      "). Increasing (" << incMax << ")." << endl;
  }
  return 0;
}
