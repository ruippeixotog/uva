#include <cstring>
#include <iostream>
#include <vector>

#define toi(ch) ((ch) - 'A')

#define MAXP 26
#define INF 0x3f3f3f3f

using namespace std;

int dist[2][MAXP][MAXP];

int main() {
  int n;
  while(cin >> n && n > 0) {
    memset(dist, 0x3f, sizeof(dist));

    while(n--) {
      char a, b, x, y; int cost;
      cin >> a >> b >> x >> y >> cost;
      dist[a == 'M'][toi(x)][toi(y)] =
        min(dist[a == 'M'][toi(x)][toi(y)], cost);

      if(b == 'B') {
        dist[a == 'M'][toi(y)][toi(x)] =
          min(dist[a == 'M'][toi(y)][toi(x)], cost);
      }
    }
    char ai, bi; cin >> ai >> bi;
    dist[0][toi(ai)][toi(ai)] = dist[1][toi(bi)][toi(bi)] = 0;

    for(int k = 0; k < MAXP; k++) {
      for(int i = 0; i < MAXP; i++) {
        for(int j = 0; j < MAXP; j++) {
          dist[0][i][j] = min(dist[0][i][j], dist[0][i][k] + dist[0][k][j]);
          dist[1][i][j] = min(dist[1][i][j], dist[1][i][k] + dist[1][k][j]);
        }
      }
    }

    vector<int> places;
    int minDist = INF - 1;
    for(int i = 0; i < MAXP; i++) {
      int iDist = dist[0][toi(ai)][i] + dist[1][toi(bi)][i];
      if(iDist == minDist) places.push_back(i);
      else if(iDist < minDist) {
        places.clear();
        places.push_back(i);
        minDist = iDist;
      }
    }

    if(places.empty()) cout << "You will never meet." << endl;
    else {
      cout << minDist;
      for(int i = 0; i < (int) places.size(); i++)
        cout << " " << char('A' + places[i]);
      cout << endl;
    }
  }
  return 0;
}
