#include <cstdio>
#include <cstring>
#include <iostream>

#define uint unsigned int

using namespace std;

int pay[256];

int main() {
  int n, k, m;
  scanf("%d\n", &n);

  while(n--) {
    memset(pay, 0, sizeof(pay));
    scanf("%d\n", &k);

    while(k--) {
      char ch; int value;
      scanf("%c %d\n", &ch, &value);
      pay[(int) ch] = value;
    }

    int total = 0;
    scanf("%d\n", &m);
    while(m) {
      int ch = getchar();
      total += pay[ch];
      if(ch == '\n') m--;
    }
    printf("%d.%.2d$\n", total / 100, total % 100);
  }
  return 0;
}
