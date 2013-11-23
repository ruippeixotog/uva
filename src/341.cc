#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <utility>
#include <vector>

#define MAXNI 10

using namespace std;

vector<pair<int, int> > graph[MAXNI];

int dist[MAXNI], prev[MAXNI];

int main() {
  int ni, tc = 0;
  while(cin >> ni && ni > 0) {
    for(int i = 0; i < ni; i++) {
      graph[i].clear();
      int ns; cin >> ns;
      for(int j = 0; j < ns; j++) {
        int to, delay; cin >> to >> delay;
        graph[i].push_back(make_pair(--to, delay));
      }
    }
    int from, to; cin >> from >> to;
    --from; --to;

    memset(dist, -1, sizeof(dist));
    priority_queue<pair<int, pair<int, int> > > q;
    q.push(make_pair(0, make_pair(-1, from)));

    while(!q.empty()) {
      pair<int, pair<int, int> > st = q.top(); q.pop();
      int curr = st.second.second;

      if(dist[curr] != -1) continue;
      dist[curr] = -st.first;
      prev[curr] = st.second.first;
      if(curr == to) break;

      for(int i = 0; i < (int) graph[curr].size(); i++) {
        q.push(make_pair(st.first - graph[curr][i].second,
          make_pair(curr, graph[curr][i].first)));
      }
    }

    stack<int> path;
    int curr = to;
    do { path.push(curr + 1); curr = prev[curr]; } while(curr != -1);

    cout << "Case " << (++tc) << ": Path =";
    while(!path.empty()) { cout << " " << path.top(); path.pop(); }
    cout << "; " << dist[to] << " second delay" << endl;
  }
  return 0;
}