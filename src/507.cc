#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
  int b; scanf("%d", &b);
  for(int t = 1; t <= b; t++) {
    int s; scanf("%d", &s);

    int best = 0, bestSt = -1, bestEnd = -1;
    int curr = 0, currSt = -1;
    for(int i = 1; i < s; i++) {
      int r; scanf("%d", &r);
      if(currSt == -1 && r > 0) currSt = i;
      else if(curr + r < 0) currSt = -1;

      curr = max(0, curr + r);
      if(curr > best || (curr == best && i - currSt > bestEnd - bestSt)) {
        best = curr; bestSt = currSt; bestEnd = i;
      }
    }
    if(best == 0) printf("Route %d has no nice parts\n", t);
    else printf("The nicest part of route %d is between stops %d and %d\n",
      t, bestSt, bestEnd + 1);
  }
  return 0;
}
