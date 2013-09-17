#include <algorithm>
#include <cstdio>
#include <cstring>

#define NMAX 20

using namespace std;

int devices[NMAX];
bool on[NMAX];

int main() {
  int n, m, c;

  int seq = 0;
  while(scanf("%d %d %d\n", &n, &m, &c) > 0) {
    if(!n && !m && !c) break;

    for(int i = 0; i < n; i++)
      scanf("%d\n", &devices[i]);

    memset(on, 0, sizeof(on));
    int cons = 0, maxCons = 0;
    bool fail = false;

    while(m--) {
      int idx;
      scanf("%d\n", &idx);
      if(fail) continue;

      if(on[--idx]) cons -= devices[idx];
      else cons += devices[idx];
      on[idx] = !on[idx];

      maxCons = max(maxCons, cons);
      if(cons > c) fail = true;
    }

    printf("Sequence %d\n", ++seq);
    printf("Fuse was %sblown.\n", fail ? "" : "not ");
    if(!fail)
      printf("Maximal power consumption was %d amperes.\n", maxCons);
    printf("\n");
  }
  return 0;
}