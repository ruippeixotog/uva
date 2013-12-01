#include <cstring>
#include <iostream>

#define MAXC 26

using namespace std;

bool first[MAXC][MAXC];
bool second[MAXC][MAXC];

int main() {
  int t; cin >> t;
  while(t--) {
    memset(first, false, sizeof(first));
    memset(second, false, sizeof(second));

    int n; cin >> n;
    while(n--) {
      char a, b; cin >> a >> b;
      first[a - 'A'][b - 'A'] = true;
    }
    int m; cin >> m;
    while(m--) {
      char a, b; cin >> a >> b;
      second[a - 'A'][b - 'A'] = true;
    }

    for(int k = 0; k < MAXC; k++) {
      for(int i = 0; i < MAXC; i++) {
        for(int j = 0; j < MAXC; j++) {
          first[i][j] = first[i][j] | (first[i][k] & first[k][j]);
          second[i][j] = second[i][j] | (second[i][k] & second[k][j]);
        }
      }
    }

    bool same = true;
    for(int i = 0; i < MAXC; i++) {
      for(int j = 0; j < MAXC; j++) {
        if(first[i][j] != second[i][j]) {
          same = false;
          break;
        }
      }
      if(!same) break;
    }

    cout << (same ? "YES" : "NO") << endl;
    if(t) cout << endl;
  }
  return 0;
}
