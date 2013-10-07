#include <algorithm>
#include <climits>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#define uint unsigned int

#define MAXN 10000
#define COLORS 9

using namespace std;

vector<int> children[MAXN];
int parent[MAXN];

int dp[MAXN][COLORS + 1];

void calcColors(int node) {
  for(uint i = 0; i < children[node].size(); i++)
    calcColors(children[node][i]);

  for(int c = 1; c <= COLORS; c++) {
    int sum = c;
    for(uint i = 0; i < children[node].size(); i++) {
      int minSum = INT_MAX;
      for(int c2 = 1; c2 <= COLORS; c2++) {
        if(c != c2) minSum = min(minSum, dp[children[node][i]][c2]);
      }
      sum += minSum;
    }
    dp[node][c] = sum;
  }
}

int main() {
  int n;
  while(cin >> n && n > 0) {
    string line;
    getline(cin, line);

    memset(parent, 0xFF, n * sizeof(int));
    for(int i = 0; i < n; i++) children[i].clear();

    while(getline(cin, line) && !line.empty()) {
      stringstream sin(line);
      int e, ch; char sep;
      sin >> e >> sep;
      while(sin >> ch) {
        parent[ch] = e;
        children[e].push_back(ch);
      }
    }

    int root = -1;
    for(int i = 0; i < n; i++) {
      if(parent[i] == -1) { root = i; break; }
    }

    calcColors(root);
    int minTotal = INT_MAX;
    for(int c = 1; c <= COLORS; c++)
      minTotal = min(minTotal, dp[root][c]);
    cout << minTotal << endl;
  }
  return 0;
}
