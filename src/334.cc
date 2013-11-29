#include <cstring>
#include <iostream>
#include <map>
#include <vector>

#define MAXNC 1000

using namespace std;

map<string, int> names;
vector<string> namesRev;
bool after[MAXNC][MAXNC];

int main() {
  int nc, tc = 0;
  while(cin >> nc && nc > 0) {
    names.clear();
    namesRev.clear();
    memset(after, false, sizeof(after));

    for(int i = 0; i < nc; i++) {
      int ne; cin >> ne;

      int last = -1, curr;
      while(ne--) {
        string name; cin >> name;
        curr = names[name] = namesRev.size();
        namesRev.push_back(name);
        if(last >= 0) after[last][curr] = true;
        last = curr;
      }
    }

    int nm; cin >> nm;
    for(int i = 0; i < nm; i++) {
      string a, b; cin >> a >> b;
      after[names[a]][names[b]] = true;
    }

    for(int k = 0; k < (int) names.size(); k++) {
      for(int i = 0; i < (int) names.size(); i++) {
        for(int j = 0; j < (int) names.size(); j++) {
          after[i][j] = after[i][j] | (after[i][k] & after[k][j]);
        }
      }
    }

    int numConc = 0;
    pair<int, int> conc[2];
    for(int i = 0; i < (int) names.size(); i++) {
      for(int j = i + 1; j < (int) names.size(); j++) {
        if(!after[i][j] & !after[j][i]) {
          if(numConc < 2) conc[numConc] = make_pair(i, j);
          numConc++;
        }
      }
    }

    cout << "Case " << (++tc) << ", ";
    if(!numConc) cout << "no concurrent events." << endl;
    else cout << numConc << " concurrent events:" << endl;

    for(int i = 0; i < numConc && i < 2; i++)
      cout << "(" << namesRev[conc[i].first] << "," <<
        namesRev[conc[i].second] << ") ";
    if(numConc > 0) cout << endl;
  }
  return 0;
}
