#include <iostream>

using namespace std;

int main() {
  int t; cin >> t;
  int total = 0;
  while(t--) {
    double l, w, d, wg;
    cin >> l >> w >> d >> wg;

    bool allowed = (((l <= 56.0 && w <= 45.0 && d <= 25.0) ||
      l + w + d <= 125.0) && wg <= 7.0);
    total += allowed;
    cout << allowed << endl;
  }
  cout << total << endl;
  return 0;
}
