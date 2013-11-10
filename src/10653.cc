#include <cstring>
#include <iostream>
#include <queue>

#define MAXR 1000
#define MAXC 1000

using namespace std;

int r, c;
pair<int, int> start, end;
bool isBomb[MAXR][MAXC];

int dist[MAXR][MAXC];

int di[] = {-1, 0, 1, 0};
int dj[] = {0, 1, 0, -1};

int bfs() {
  memset(dist, -1, sizeof(dist));
  queue<pair<int, int> > q;
  q.push(start);
  dist[start.first][start.second] = 0;

  while(!q.empty()) {
    pair<int, int> st = q.front(); q.pop();
    for(int d = 0; d < 4; d++) {
      pair<int, int> newSt(st.first + di[d], st.second + dj[d]);
      if(newSt.first < 0 || newSt.second < 0 || newSt.first >= r ||
        newSt.second >= c || isBomb[newSt.first][newSt.second]) continue;

      if(newSt == end) return dist[st.first][st.second] + 1;

      if(dist[newSt.first][newSt.second] == -1) {
        q.push(newSt);
        dist[newSt.first][newSt.second] = dist[st.first][st.second] + 1;
      }
    }
  }
  return -1;
}

int main() {
  while(cin >> r >> c && r > 0) {
    memset(isBomb, false, sizeof(isBomb));
    int nr; cin >> nr;
    while(nr--) {
      int i, nb; cin >> i >> nb;
      while(nb--) {
        int j; cin >> j;
        isBomb[i][j] = true;  
      }
    }
    cin >> start.first >> start.second;
    cin >> end.first >> end.second;
    cout << bfs() << endl;
  }
  return 0;
}
