#include <cstdio>
#include <iostream>

using namespace std;

int main() {
  double currX = 0.0;
  double currSpeed = 0;
  int currTime = 0;

  string line;
  while(getline(cin, line)) {
    int h, m, s, speed = -1;
    sscanf(line.c_str(), "%d:%d:%d %d", &h, &m, &s, &speed);

    int time = s + 60 * (m + 60 * h);
    int dt = time - currTime;
    currX += currSpeed * dt / 3600.0;
    currTime = time;

    if(speed >= 0) currSpeed = speed;
    else printf("%.2d:%.2d:%.2d %.2f km\n", h, m, s, currX);
  }
  return 0;
}
