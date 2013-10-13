#include <cmath>
#include <cstring>
#include <iostream>

#define uint unsigned int

#define MAXD 20
#define MAX_NODES 524288

using namespace std;

bool tree[MAX_NODES];

int dropBall(int d, int node = 1, int curr = 1) {
  if(d == curr) return node;
  tree[node] = !tree[node];
  if(tree[node]) return dropBall(d, node * 2, curr + 1);
  return dropBall(d, node * 2 + 1, curr + 1);
}

int main() {
  int t; cin >> t;
  while(t--) {
    int d, n; cin >> d >> n;
    memset(tree, 0, pow(2, d - 1) * sizeof(bool));
    while(n-- > 1) cerr << "Dropped at " << dropBall(d) << endl;
    cout << dropBall(d) << endl;
  }
  return 0;
}