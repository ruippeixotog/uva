#include <iostream>

#define MAXN 100

using namespace std;

char field[MAXN];

int main() {
  int t, n;
  cin >> t;
  for(int m = 1; m <= t; m++) {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> field[i];

    int count = 0;
    for(int i = 0; i < n; i++) {
      if(field[i] != '#') {
        field[i] = '#';
        if(i + 1 < n) field[i + 1] = '#';
        if(i + 2 < n) field[i + 2] = '#';
        count++;
      }
    }
    cout << "Case " << m << ": " << count << endl;
  }
  return 0;
}
