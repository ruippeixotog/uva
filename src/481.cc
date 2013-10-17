#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

#define uint unsigned int

using namespace std;

vector<int> arr, dp, prev;

int main() {
  int n;
  while(cin >> n) arr.push_back(n);
  prev.resize(arr.size());
  dp.resize(1, -1);

  int m = 0;
  for(uint i = 0; i < arr.size(); i++) {
    int a = 0, b = m;
    while(a < b) {
      int mid = a + (b - a) / 2 + 1;
      if(arr[dp[mid]] < arr[i]) a = mid;
      else b = mid - 1;
    }
    prev[i] = dp[a];

    if(a == m || arr[i] <= arr[dp[a + 1]]) {
      m = max(m, a + 1);
      dp.resize(m + 1);
      dp[a + 1] = i;
    }
  }

  stack<int> seq;
  int idx = dp[m];
  while(idx != -1) { seq.push(arr[idx]); idx = prev[idx]; }

  cout << seq.size() << endl << "-" << endl;
  while(!seq.empty()) { cout << seq.top() << endl; seq.pop(); }

  return 0;
}