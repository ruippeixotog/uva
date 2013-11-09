#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <stack>
#include <vector>

#define MAXP 1000

using namespace std;

vector<int> graph[MAXP];

int dfsCount, dfsNumber[MAXP], dfsLow[MAXP];
stack<int> dfsScc;
bool inDfsScc[MAXP];

int numSccs;

int nextId;
map<string, int> personId; 

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
    while(!dfsScc.empty() && dfsScc.top() != k) {
      inDfsScc[dfsScc.top()] = false; dfsScc.pop();
    }
    inDfsScc[dfsScc.top()] = false; dfsScc.pop();
    numSccs++;
  }
}

int main() {
  int p, t;
  while(cin >> p >> t && p > 0) {
    string name;
    getline(cin, name);

    nextId = 0;
    personId.clear();
    for(int i = 0; i < p; i++) {
      getline(cin, name);
      personId[name] = nextId++;
    }

    for(int i = 0; i < p; i++) graph[i].clear();
    while(t--) {
      string trusts;
      getline(cin, name); getline(cin, trusts);
      graph[personId[name]].push_back(personId[trusts]);
    }

    dfsCount = 0;
    memset(dfsNumber, 0, sizeof(dfsNumber));
    numSccs = 0;
    for(int i = 0; i < p; i++) {
      if(!dfsNumber[i]) findScc(i);
    }

    cout << numSccs << endl;
  }
  return 0;
}
