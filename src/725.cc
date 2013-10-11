#include <cstdio>
#include <iostream>

#define ll long long

using namespace std;

bool allDistinct(ll n) {
  bool used[10] = {0};
  for(int i = 0; i < 10; i++, n /= 10) {
    if(used[n % 10]) return false;
    used[n % 10] = true;
  }
  return true;
}

int main() {
  int n, t = 0;
  while(cin >> n && n > 0) {
    if(t++) cout << endl;

    bool exists = false;
    for(int i = 1234; i <= 98765; i++) {
      int num = i * n;
      if(num > 98765) break;
      if(allDistinct(num * (ll) 100000 + i)) {
        printf("%05d / %05d = %d\n", num, i, n);
        exists = true;
      }
    }
    if(!exists) printf("There are no solutions for %d.\n", n);
  }
  return 0;
}