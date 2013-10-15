#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

int p, q, r, s, t, u;

double f(double x) {
  return p * exp(-x) + q * sin(x) + r * cos(x) +
    s * tan(x) + t * pow(x, 2) + u;
}

int main() {
  while(cin >> p >> q >> r >> s >> t >> u) {
    double min = 0.0, ymin = f(min);
    double max = 1.0, ymax = f(max);
    if(ymin * ymax > 0) cout << "No solution" << endl;
    else if(ymin == 0) printf("%.4f\n", 0.0);
    else {
      while(max - min > 1e-7) {
        double mid = (max + min) / 2, ymid = f(mid);
        if(ymax * ymid > 0) { max = mid; ymax = ymid; }
        else { min = mid; ymin = ymid; }
      }
      printf("%.4f\n", min);
    }
  }
  return 0;
}
