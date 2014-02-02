#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int t; cin >> t;
  for(int tc = 1; tc <= t; tc++) {
    int n; cin >> n;

    int best = 0;
    while(n--) {
      int c; cin >> c;
      best = max(best, c);
    }
    cout << "Case " << tc << ": " << best << endl;
  }
  return 0;
}
