#include <algorithm>
#include <cmath>
#include <cstdio>

#define MAXC 5

using namespace std;

int spec[2 * MAXC];
int mass[MAXC];

int main() {
  int c, s, t = 0;
  while(scanf("%d %d", &c, &s) > 0) {
    for(int i = 0; i < s; i++) scanf("%d", spec + i);
    for(int i = s; i < 2 * c; i++) spec[i] = 0;
    sort(spec, spec + 2 * c);

    printf("Set #%d\n", ++t);
    double avg = 0.0;
    for(int i = 0; i < c; i++) {
      avg += mass[i] = spec[i] + spec[2 * c - i - 1];
      printf(" %d:", i);
      if(spec[i]) printf(" %d", spec[i]);
      if(spec[2 * c - i - 1]) printf(" %d", spec[2 * c - i - 1]);
      printf("\n");
    }
    avg /= c;
    double imbalance = 0.0;
    for(int i = 0; i < c; i++)
      imbalance += abs(mass[i] - avg);
    printf("IMBALANCE = %.5f\n\n", imbalance);
  }
  return 0;
}