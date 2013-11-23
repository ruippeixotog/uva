#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <sstream>
#include <utility>
#include <vector>

#define MAXN 5
#define MAXK 100

using namespace std;

vector<int> floors[MAXN];
int speed[MAXN];

vector<int> elevs[MAXK];
int dist[MAXK];

int main() {
  int n, k;
  while(cin >> n >> k) {
    for(int i = 0; i < n; i++) cin >> speed[i];
    for(int i = 0; i < MAXK; i++) elevs[i].clear();

    string line; getline(cin, line);
    for(int i = 0; i < n; i++) {
      getline(cin, line);
      stringstream sin(line);

      floors[i].clear();
      int fl;
      while(sin >> fl) {
        floors[i].push_back(fl);
        elevs[fl].push_back(i);
      }
    }

    memset(dist, -1, sizeof(dist));
    priority_queue<pair<int, int> > q;
    q.push(make_pair(60, 0));

    while(!q.empty()) {
      pair<int, int> st = q.top(); q.pop();
      int curr = st.second;

      if(dist[curr] != -1) continue;
      dist[curr] = max(-st.first, 0);
      if(curr == k) break;

      for(int i = 0; i < (int) elevs[curr].size(); i++) {
        int e = elevs[curr][i];
        for(int j = 0; j < (int) floors[e].size(); j++) {
          int next = floors[e][j];
          if(curr == next) continue;
          q.push(make_pair(
            st.first - speed[e] * abs(curr - next) - 60,
            next));
        }
      }
    }

    if(dist[k] == -1) cout << "IMPOSSIBLE" << endl;
    else cout << dist[k] << endl;
  }
  return 0;
}