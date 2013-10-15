#include <cstdio>
#include <set>
#include <string>

#define siterator set<pair<int, string> >::iterator

#define MAXA 16

using namespace std;

char agency[MAXA + 1];

int main() {
  int t; scanf("%d", &t);
  for(int k = 1; k <= t; k++) {
    int n, m, l; scanf("%d %d %d", &n, &m, &l);

    set<pair<int, string> > costs;
    while(l--) {
      int ca, cb; scanf("%*[^A-Z]%[A-Z]:%d,%d", agency, &ca, &cb);
      int curr = n, cost = 0;
      while(curr > m) {
        int half = (curr + 1) / 2;
        if(half > curr - m) { cost += ca * (curr - m); break; }
        cost += ca * half < cb ? ca * half : cb;
        curr -= half;
      }
      costs.insert(pair<int, string>(cost, string(agency)));
    }

    printf("Case %d\n", k);
    for(siterator it = costs.begin(); it != costs.end(); it++)
      printf("%s %d\n", it->second.c_str(), it->first);
  }
  return 0;
}
