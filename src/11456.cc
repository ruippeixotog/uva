#include <algorithm>
#include <cstring>
#include <iostream>

#define MAXN 2000

using namespace std;

int arr[MAXN * 2], dp[MAXN];

int main() {
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[n + i];
    for(int i = 0; i < n; i++) arr[i] = arr[2 * n - i - 1];
    memset(dp, 0, 2 * n * sizeof(int));
    dp[0] = -1;

    int m = 0;
    for(int i = 0; i < 2 * n; i++) {
      int a = 0, b = m;
      while(a < b) {
        int mid = a + (b - a) / 2 + 1;
        if(arr[dp[mid]] > arr[i]) a = mid;
        else b = mid - 1;
      }

      if(a == m || arr[i] > arr[dp[a + 1]]) {
        m = max(m, a + 1);
        dp[a + 1] = i;
      }
    }
    cout << m << endl;
  }
  return 0;
}
