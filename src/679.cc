#include <iostream>

using namespace std;

int main() {
  int t; cin >> t;
  while(t--) {
    int d, n; cin >> d >> n;

    n--;
    int node = 1;
    for(int i = 1; i < d; i++) {
      if(n % 2 == 0) node = node * 2;
      else node = node * 2 + 1;
      n /= 2;
    }
    cout << node << endl;
  }
  return 0;
}