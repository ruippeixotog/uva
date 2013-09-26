#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

#define MAXC 100
#define MAXP 9

using namespace std;

int solved[MAXC];
int pending[MAXC][MAXP];
int penalty[MAXC];
bool submitted[MAXC];

int teams[MAXC];

bool teamcmp(int i, int j) {
  int cmp = solved[i] - solved[j];
  if(cmp != 0) return cmp > 0;
  cmp = penalty[j] - penalty[i];
  if(cmp != 0) return cmp > 0;
  return i < j;
}

int main() {
  int n;
  scanf("%d\n\n", &n);

  while(n--) {
    memset(solved, 0, sizeof(solved));
    memset(pending, 0, sizeof(pending));
    memset(penalty, 0, sizeof(penalty));
    memset(submitted, 0, sizeof(submitted));

    int c, p, t; char l;
    string line;
    while(getline(cin, line) && !line.empty()) {
      sscanf(line.c_str(), "%d %d %d %c\n", &c, &p, &t, &l);
      submitted[--c] = true;
      if(pending[c][--p] != -1) {
        if(l == 'C') {
          solved[c]++;
          penalty[c] += pending[c][p] + t;
          pending[c][p] = -1;
        } else if(l == 'I') {
          pending[c][p] += 20;
        }
      }
    }

    for(int i = 0; i < MAXC; i++) teams[i] = i;
    sort(teams, teams + MAXC, teamcmp);

    for(int i = 0; i < MAXC; i++) {
      if(submitted[teams[i]]) {
        printf("%d %d %d\n",
          teams[i] + 1, solved[teams[i]], penalty[teams[i]]);
      }
    }
    if(n) printf("\n");
  }
  return 0;
}
