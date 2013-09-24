#include <cstdio>

using namespace std;

int main() {
  int in, out;
  char* inArr = (char*) &in;
  char* outArr = (char*) &out;
  while(scanf("%d\n", &in) > 0) {
    for(int i = 0; i < 4; i++)
      outArr[i] = inArr[3 - i];
    printf("%d converts to %d\n", in, out);
  }
  return 0;
}