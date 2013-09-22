#include <cstdio>

using namespace std;

int main() {
  int t;
  scanf("%d\n", &t);

  while(t--) {
    int s, d;
    scanf("%d %d\n", &s, &d);
    if((s + d) % 2 != 0) printf("impossible\n");
    else {
      int winner = (s + d) / 2;
      if(s - winner < 0) printf("impossible\n");
      else printf("%d %d\n", winner, s - winner);
    }
  }

  return 0;
}
