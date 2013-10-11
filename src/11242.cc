#include <algorithm>
#include <cstdio>
#include <iostream>
#include <set>

#define MAXF 10

#define siterator set<Ratio>::iterator

using namespace std;

struct Ratio {
  int r, f;
  Ratio(int _r, int _f): r(_r), f(_f) {}

  double spread(const Ratio& rat) const {
    return (rat.r * f) / (double) (rat.f * r);
  }
  bool operator<(const Ratio& rat) const {
    return r * rat.f < rat.r * f;
  }
};

int fs[MAXF], rs[MAXF];

int main() {
  int f, r;
  while(cin >> f && f > 0) {
    cin >> r;
    for(int i = 0; i < f; i++) cin >> fs[i];
    for(int i = 0; i < r; i++) cin >> rs[i];

    set<Ratio> ratios;
    for(int i = 0; i < f; i++) {
      for(int j = 0; j < r; j++) {
        ratios.insert(Ratio(rs[j], fs[i]));
      }
    }
    siterator last = ratios.begin();
    siterator it = ratios.begin()++;
    double best = 0.0;
    for(it++; it != ratios.end(); it++, last++)
      best = max(best, last->spread(*it));

    printf("%.2f\n", best);
  }
  return 0;
}