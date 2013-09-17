#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
  int h, u, d, f;
  
  while(scanf("%d %d %d %d\n", &h, &u, &d, &f) > 0) {
    if(h == 0) break;

    double fat = u * f / 100.0;

    double pos = 0.0;
    int day = 0;
    bool awake = true;

    while(pos >= 0.0 && pos <= h) {
      if(awake) {
        day++;
        pos += max(0.0, u - (day - 1) * fat);
      }
      else pos -= d;
      awake = !awake;
    }

    printf("%s on day %d\n", pos > h ? "success" : "failure", day);
  }
  return 0;
}