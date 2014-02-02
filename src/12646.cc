#include <iostream>

using namespace std;

int main() {
  int a, b, c;
  while(cin >> a >> b >> c) {
    int sum = a + b + c;
    if(sum == 0 || sum == 3) cout << "*" << endl;
    else if(sum == 1) cout << (a ? "A" : b ? "B" : "C") << endl;
    else cout << (!a ? "A" : !b ? "B" : "C") << endl;
  }
  return 0;
}
