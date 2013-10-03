#include <algorithm>
#include <climits>
#include <iostream>
#include <map>

#define miterator map<int, int>::iterator

#define MAXN 1000000

using namespace std;

map<int, int> graph[MAXN];

pair<bool, int> handleCycle(int src, int curr, int last, int best) {
  if(last != -1 && curr == src)
    return pair<bool, int>(true, best);

  map<int, int>& adjs = graph[curr];

  for(miterator it = adjs.begin(); it != adjs.end(); it++) {
    if(it->first != last) {
      pair<bool, int> res =
        handleCycle(src, it->first, curr, max(it->second, best));
      if(res.first) {
        if(res.second == it->second) {
          adjs.erase(it->first);
          res.second = -res.second;
        }
        return res;
      }
    }
  }
  return pair<bool, int>(false, INT_MIN); 
}

int main() {
  int t = 0, n, k, m;
  while(cin >> n) {
    for(int i = 0; i < n; i++)
      graph[i].clear();

    int oldCost = 0;
    int a, b, cost;
    for(int i = 0; i < n - 1; i++) {
      cin >> a >> b >> cost;
      graph[a][b] = cost;
      graph[b][a] = cost;
      oldCost += cost;
    }

    int newCost = oldCost;
    cin >> k;
    for(int i = 0; i < k; i++) {
      cin >> a >> b >> cost;
      graph[a][b] = cost;
      graph[b][a] = cost;
      newCost += handleCycle(a, a, -1, INT_MIN).second + cost;
    }

    cin >> m;
    for(int i = 0; i < m; i++)
      cin >> a >> b >> cost;

    if(t++) cout << endl;
    cout << oldCost << endl;
    cout << newCost << endl;
  }
  return 0;
}