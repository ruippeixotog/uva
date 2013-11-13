#include <cstring>
#include <iostream>
#include <queue>

#define MAXR 1000
#define MAXC 1000

using namespace std;

int r, c;
char map[MAXR][MAXC];
int dist[MAXR][MAXC];
bool onFire[MAXR][MAXC];

int di[] = {-1, 0, 1, 0};
int dj[] = {0, 1, 0, -1};

struct Event {
  bool joe; int i, j;
  Event() {}
  Event(bool _joe, int _i, int _j): joe(_joe), i(_i), j(_j) {}
};

int bfs(queue<Event>& q) {
  while(!q.empty()) {
    Event ev = q.front(); q.pop();
    for(int d = 0; d < 4; d++) {
      Event nev(ev.joe, ev.i + di[d], ev.j + dj[d]);
      if(nev.i < 0 || nev.j < 0 || nev.i >= r || nev.j >= c) {
        if(ev.joe) return dist[ev.i][ev.j] + 1;
        else continue;
      }
      if(map[nev.i][nev.j] == '#') continue;

      if(dist[nev.i][nev.j] == -1 && !onFire[nev.i][nev.j]) {
        q.push(nev);
        if(ev.joe) dist[nev.i][nev.j] = dist[ev.i][ev.j] + 1;
        else onFire[nev.i][nev.j] = true;
      }
    }
  }
  return -1;
}

int main() {
  int t; cin >> t;
  while(t--) {
    cin >> r >> c;

    memset(dist, -1, sizeof(dist));
    memset(onFire, false, sizeof(onFire));
    
    queue<Event> events;
    Event joe(true, -1, -1);

    for(int i = 0; i < r; i++) {
      for(int j = 0; j < c; j++) {
        cin >> map[i][j];
        if(map[i][j] == 'J') { joe.i = i; joe.j = j; }
        else if(map[i][j] == 'F')
          events.push(Event(false, i, j));
      }
    }
    events.push(joe);
    dist[joe.i][joe.j] = 0;

    int t = bfs(events);
    if(t < 0) cout << "IMPOSSIBLE" << endl;
    else cout << t << endl;
  }
  return 0;
}
