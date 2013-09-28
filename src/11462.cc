#include <cstdio>
#include <cstring>

#define MAX_AGE 100

using namespace std;

int freq[MAX_AGE];

int main() {
  int n;
  while(scanf("%d\n", &n) > 0 && n > 0) {
    memset(freq, 0, sizeof(freq));

    while(n--) {
      int age;
      scanf("%d\n", &age);
      freq[age]++;
    }

    bool first = true;
    for(int i = 0; i < MAX_AGE; i++) {
      for(int j = 0; j < freq[i]; j++) {
        if(first) { printf("%d", i); first = false; }
        else printf(" %d", i);
      }
    }
    printf("\n");
  }
  return 0;
}
