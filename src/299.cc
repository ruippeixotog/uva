#include <cstdio>

#define MAXL 50

using namespace std;

int order[MAXL];

inline void swap(int& i, int& j) {
  int tmp = i; i = j; j = tmp;
}

int main() {
  int n, l;
  scanf("%d\n", &n);

  while(n--) {
    scanf("%d\n", &l);
    for(int i = 0; i < l; i++)
      scanf("%d\n", &order[i]);

    int swaps = 0;
    for(int i = 0; i < l; i++) {
      int j = i;
      while(order[j] != i + 1) j++;
      while(j > i) {
        swap(order[j - 1], order[j]);
        swaps++; j--;
      }
    }
    printf("Optimal train swapping takes %d swaps.\n", swaps);
  }
  return 0;
}