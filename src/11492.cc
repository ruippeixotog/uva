#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

#define uint unsigned int

using namespace std;

map< string, vector< pair<string, string> > > graph;

struct State {
  string currLang;
  char lastLetter;
  int letterCount;

  pair<string, char> stateKey() {
    return pair<string, int>(currLang, lastLetter);
  }

  State(string curr, char lett, int cnt):
    currLang(curr), lastLetter(lett), letterCount(cnt) {}

  bool operator<(const State& st) const {
    return letterCount > st.letterCount;
  }
};

int main() {
  int n; string beginLang, endLang;
  while(cin >> n >> beginLang >> endLang) {
    graph.clear();

    string srcLang, destLang, word;
    while(n--) {
      cin >> srcLang >> destLang >> word;
      graph[srcLang].push_back(pair<string, string>(destLang, word));
      graph[destLang].push_back(pair<string, string>(srcLang, word));
    }

    priority_queue<State> queue;
    queue.push(State(beginLang, '\0', 0));

    set< pair<string, char> > visitedStates;

    int best = -1;
    while(!queue.empty()) {
      State st = queue.top();
      queue.pop();

      if(visitedStates.count(st.stateKey())) continue;
      visitedStates.insert(st.stateKey());

      if(st.currLang == endLang) {
        best = st.letterCount;
        break;
      }

      vector< pair<string, string> > adjs = graph[st.currLang];
      for(uint i = 0; i < adjs.size(); i++) {
        string& adjWord = adjs[i].second;
        if(adjWord[0] != st.lastLetter) {
          queue.push(State(
            adjs[i].first,
            adjWord[0],
            st.letterCount + adjWord.length()));
        }
      }
    }
    if(best == -1) cout << "impossivel" << endl;
    else cout << best << endl;
  }
  return 0;
}
