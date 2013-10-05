#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, p;
  string line;

  cin >> n;
  while(n--) {
    cin >> p;
    getline(cin, line);

    vector<int> bestIdx;
    int best = INT_MAX;
    for(int i = 1; i <= p; i++) {
      getline(cin, line);
      int cnt = count(line.begin(), line.end(), ' ') + 1;
      if(cnt < best) { bestIdx.clear(); best = cnt; }
      if(cnt == best) bestIdx.push_back(i);
    }

    cout << bestIdx[0];
    for(int i = 1; i < int(bestIdx.size()); i++)
      cout << " " << bestIdx[i];
    cout << endl;
  }

  return 0;
}
