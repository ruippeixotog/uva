#include <algorithm>
#include <iostream>
#include <string>

#define ull unsigned long long

using namespace std;

ull fact(int n) {
  ull v = 1;
  for(int i = 2; i <= n; i++) v *= i;
  return v;
}

int main() {
  int t;
  cin >> t;

  while(t--) {
    string str; ull n;
    cin >> str >> n;
    sort(str.begin(), str.end());

    ull range = fact(str.length());
    string perm;

    while(!str.empty()) {
      range /= str.length();
      int partIdx = n / range;
      n -= range * partIdx;

      perm += str[partIdx];
      str.erase(partIdx, 1);
    }
    cout << perm << endl;
  }
  return 0;
}