#include <algorithm>
#include <cstdio>
#include <cstring>

#define NMAX 1000000

#define uint unsigned int 

using namespace std;

uint mem[NMAX];

int cycleLength(uint n) {
  if(n < NMAX && mem[n]) {
    return mem[n];
  }
  uint len = 1 + cycleLength(n % 2 == 0 ? n / 2 : 3 * n + 1);
  if(n < NMAX) mem[n] = len;
  return len;
}

int main() {
  memset(mem, 0, sizeof(mem));
  mem[1] = 1;

  uint i, j;
  while(scanf("%d %d\n", &i, &j) > 0) {
    int cl = 0;
    for(uint k = min(i, j); k <= max(i, j); k++) {
      cl = max(cl, cycleLength(k));
    }
    printf("%d %d %d\n", i, j, cl);
  }
  return 0;
}