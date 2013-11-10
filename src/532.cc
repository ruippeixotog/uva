#include <cstring>
#include <iostream>
#include <queue>

#define MAXL 30
#define MAXR 30
#define MAXC 30

using namespace std;

int maxl, maxr, maxc;
int stl, str, stc;
char level[MAXL][MAXR][MAXC];

int dist[MAXL][MAXR][MAXC];

int dl[] = {0, 0, 0, 0, -1, 1};
int dr[] = {-1, 0, 1, 0, 0, 0};
int dc[] = {0, 1, 0, -1, 0, 0};

struct Coord {
  int l, r, c;
  Coord(int _l, int _r, int _c): l(_l), r(_r), c(_c) {}
  bool valid() {
    return l >= 0 && r >= 0 && c >= 0 &&
      l < maxl && r < maxr && c < maxc && level[l][r][c] != '#';
  }
};

int bfs() {
  memset(dist, -1, sizeof(dist));
  queue<Coord> q;
  q.push(Coord(stl, str, stc));
  dist[stl][str][stc] = 0;

  while(!q.empty()) {
    Coord st = q.front(); q.pop();
    for(int d = 0; d < 6; d++) {
      Coord newSt(st.l + dl[d], st.r + dr[d], st.c + dc[d]);
      if(!newSt.valid()) continue;

      if(level[newSt.l][newSt.r][newSt.c] == 'E')
        return dist[st.l][st.r][st.c] + 1;

      if(dist[newSt.l][newSt.r][newSt.c] == -1) {
        q.push(newSt);
        dist[newSt.l][newSt.r][newSt.c] = dist[st.l][st.r][st.c] + 1;
      }
    }
  }
  return -1;
}

int main() {
  while(cin >> maxl >> maxr >> maxc && maxl > 0) {
    for(int l = 0; l < maxl; l++) {
      for(int r = 0; r < maxr; r++) {
        for(int c = 0; c < maxc; c++) {
          cin >> level[l][r][c];
          if(level[l][r][c] == 'S') { stl = l; str = r; stc = c; }
        }
      }
    }
    int t = bfs();
    if(t > 0) cout << "Escaped in " << t << " minute(s)." << endl;
    else cout << "Trapped!" << endl;
  }
  return 0;
}
