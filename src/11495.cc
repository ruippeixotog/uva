#include <cstdio>
#include <cstring>

#define MAXN 100000

using namespace std;

int arr[MAXN];
int tmp[MAXN];

int mergeSort(int st, int end) {
  if(end - st < 2) return 0;

  int mid = (end + st) / 2;
  int moves = mergeSort(st, mid) + mergeSort(mid, end);

  int lcur = st, rcur = mid, tcur = st;
  while(lcur < mid && rcur < end) {
    if(arr[lcur] < arr[rcur]) tmp[tcur++] = arr[lcur++];
    else {
      tmp[tcur++] = arr[rcur++];
      moves += mid - lcur;
    }
  }
  if(lcur < mid)
    memcpy(arr + tcur, arr + lcur, (mid - lcur) * sizeof(int));
  else
    memcpy(arr + tcur, arr + rcur, (end - rcur) * sizeof(int));
  memcpy(arr + st, tmp + st, (tcur - st) * sizeof(int));
  return moves;
}

int main() {
  int n;
  while(scanf("%d", &n) > 0 && n > 0) {
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    int moves = mergeSort(0, n);
    printf("%s\n", moves % 2 == 0 ? "Carlos" : "Marcelo");
  }
  return 0;
}
