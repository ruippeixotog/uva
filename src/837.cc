#include <algorithm>
#include <cstdio>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main() {
  int t;
  scanf("%d\n", &t);

  while(t--) {
    scanf("\n");

    vector<double> coefs; 
    map<double, int> events;

    int nl;
    scanf("%d\n", &nl);

    for(int i = 1; i <= nl; i++) {
      double x1, x2, r;
      scanf("%lf %*f %lf %*f %lf\n", &x1, &x2, &r);

      coefs.push_back(r);
      events.insert(pair<double, int>(min(x1, x2), i));
      events.insert(pair<double, int>(max(x1, x2), -i));
    }

    printf("%ld\n", events.size() + 1);

    double level = 1.0;
    char lastEv[6] = "-inf";
    for(map<double, int>::iterator it = events.begin(); it != events.end(); it++) {
      printf("%s %.3lf %.3lf\n", lastEv, it->first, level);

      if(it->second > 0) level *= coefs[it->second - 1];
      else level /= coefs[-it->second - 1];

      sprintf(lastEv, "%.3f", it->first);
    }

    printf("%s +inf 1.000\n", lastEv);

    if(t != 0) printf("\n");
  }
  return 0;
}