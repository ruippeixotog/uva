#include <iostream>
#include <stack>

#define ll long long

#define MAXM 500

using namespace std;

int books[MAXM];

int distribute(int k, int m, ll p) {
  bool margin = false;
  int idx = 0;
  for(int i = 0; i < k; i++) {
    ll sum = 0;
    for(; idx < m && sum + books[idx] <= p; idx++)
      sum += books[idx];
    margin = margin || p - sum > 0;
  }
  if(idx < m) return -1;
  return margin;
}

void printDistrib(int k, int m, int p) {
  stack<int> limits;
  int idx = m - 1;
  for(int i = k - 1; i > 0; i--) {
    int sum = 0;
    while(idx >= 0 && sum + books[idx] <= p && idx >= i)
      sum += books[idx--];
    limits.push(idx + 1);
  }
  cout << books[0];
  for(int i = 1; i < m; i++) {
    if(!limits.empty() && limits.top() == i) {
      cout << " /"; limits.pop();
    }
    cout << " " << books[i];
  }
  cout << endl;
}

int main() {
  int t; cin >> t; 
  while(t--) {
    int k, m; cin >> m >> k;

    ll min = 1, max = 0;
    for(int i = 0; i < m; i++) {
      cin >> books[i];
      max += books[i];
    }

    while(min < max) {
      ll mid = (max + min) / 2;
      int res = distribute(k, m, mid);
      if(res == 0) min = max;
      else if(res < 0) min = mid + 1;
      else max = mid;
    }
    printDistrib(k, m, min);
  }
  return 0;
}