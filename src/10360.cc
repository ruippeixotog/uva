#include <algorithm>
#include <cstdio>
#include <cstring>

#define XSIZE 1025
#define YSIZE 1025
#define NMAX 20000

using namespace std;

int map[XSIZE + 1][YSIZE + 1];

int main() {

  int t;
  scanf("%d\n", &t);

  while(t--) {
    memset(map, 0, sizeof(map));

    int d, n;
    scanf("%d\n%d\n", &d, &n);

    for(int i = 0; i < n; i++) {
      int x, y, size;
      scanf("%d %d %d\n", &x, &y, &size);

      for(int j = max(0, x - d); j <= min(x + d, XSIZE - 1); j++) {
        map[j][max(0, y - d)] += size;
        map[j][min(YSIZE, y + d + 1)] -= size;
      }
    }

    int bestX = 0, bestY = 0;
    int bestKilled = 0;

    for(int i = 0; i < XSIZE; i++) {
      int currKilled = 0;

      for(int j = 0; j < YSIZE; j++) {
        currKilled += map[i][j];
        if(currKilled > bestKilled) {
          bestX = i; bestY = j; bestKilled = currKilled;
        }
      }
    }
    printf("%d %d %d\n", bestX, bestY, bestKilled);
  }
  return 0;
}
