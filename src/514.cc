#include <cstdio>
#include <stack>

using namespace std;

int main() {
  int n, a = -1;
  while(scanf("%d\n", &n) > 0 && n > 0) {
    while(true) {
      stack<int> station; station.push(0);
      int nextCoach = 1;
      bool possible = true;

      for(int i = 0; i < n; i++) {
        scanf("%d\n", &a);
        if(!a) break;
        if(!possible) continue;

        while(station.top() != a && nextCoach <= n) {
          station.push(nextCoach++);
        }

        if(station.top() == a) station.pop();
        else possible = false;
      }

      if(a) printf("%s\n", possible ? "Yes" : "No");
      else break;
    }
    printf("\n");
  }
  return 0;
}