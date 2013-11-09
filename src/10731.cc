#include <algorithm>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>

#define MAXA 26

using namespace std;

vector<int> graph[MAXA];

int dfsCount, dfsNumber[MAXA], dfsLow[MAXA];
stack<int> dfsScc;
bool inDfsScc[MAXA];

vector<vector<int> > sccs;

void findScc(int k) {
  dfsNumber[k] = dfsLow[k] = ++dfsCount;
  dfsScc.push(k); inDfsScc[k] = true;

  for(int i = 0; i < (int) graph[k].size(); i++) {
    if(!dfsNumber[graph[k][i]])
      findScc(graph[k][i]);

    if(inDfsScc[graph[k][i]])
      dfsLow[k] = min(dfsLow[k], dfsLow[graph[k][i]]);
  }

  if(dfsLow[k] == dfsNumber[k]) {
    vector<int> scc;
    while(!dfsScc.empty() && dfsScc.top() != k) {
      scc.push_back(dfsScc.top());
      inDfsScc[dfsScc.top()] = false; dfsScc.pop();
    }
    scc.push_back(dfsScc.top());
    inDfsScc[dfsScc.top()] = false; dfsScc.pop();

    sort(scc.begin(), scc.end());
    sccs.push_back(scc);
  }
}

char answers[5];
bool used[MAXA];

int main() {
  int n, tc = 0;
  while(cin >> n && n > 0) {
    if(tc++) cout << endl;

    for(int i = 0; i < MAXA; i++) graph[i].clear();
    memset(used, false, sizeof(used));
    while(n--) {
      for(int i = 0; i < 5; i++) {
        cin >> answers[i];
        used[answers[i] - 'A'] = true;
      }
      char selected; cin >> selected;
      for(int i = 0; i < 5; i++)
        graph[selected - 'A'].push_back(answers[i] - 'A');
    }

    dfsCount = 0;
    memset(dfsNumber, 0, sizeof(dfsNumber));
    sccs.clear();
    for(int i = 0; i < MAXA; i++) {
      if(used[i] && !dfsNumber[i]) findScc(i);
    }

    sort(sccs.begin(), sccs.end());

    for(int i = 0; i < (int) sccs.size(); i++) {
      cout << char('A' + sccs[i][0]);
      for(int j = 1; j < (int) sccs[i].size(); j++) 
        cout << ' ' << char('A' + sccs[i][j]);
      cout << endl;
    }
  }
  return 0;
}
