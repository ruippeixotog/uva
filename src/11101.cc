#include <cstring>
#include <iostream>
#include <queue>
#include <set>
#include <utility>

#define MAXA 2000
#define MAXS 2000

using namespace std;

set<pair<int, int> > goals;

int dist[MAXA][MAXS];

int di[] = {-1, 0, 1, 0};
int dj[] = {0, 1, 0, -1};

int bfs(queue<pair<int, int> >& q) {
  while(!q.empty()) {
    pair<int, int> st = q.front(); q.pop();
    for(int d = 0; d < 4; d++) {
      pair<int, int> newSt(st.first + di[d], st.second + dj[d]);
      if(newSt.first < 0 || newSt.second < 0 || newSt.first >= MAXA ||
        newSt.second >= MAXS) continue;

      if(goals.count(newSt)) return dist[st.first][st.second] + 1;

      if(dist[newSt.first][newSt.second] == -1) {
        q.push(newSt);
        dist[newSt.first][newSt.second] = dist[st.first][st.second] + 1;
      }
    }
  }
  return -1;
}

int main() {
  int pa, pb;
  while(cin >> pa && pa > 0) {
    memset(dist, -1, sizeof(dist));
    queue<pair<int, int> > begins;
    while(pa--) {
      int a, s; cin >> a >> s;
      begins.push(make_pair(a, s));
      dist[a][s] = 0;
    }
    cin >> pb;
    goals.clear();
    while(pb--) {
      int a, s; cin >> a >> s;
      goals.insert(make_pair(a, s));
    }
    cout << bfs(begins) << endl;
  }
  return 0;
}
