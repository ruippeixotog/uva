#include <cmath>
#include <iostream>
#include <vector>

#define uint unsigned int

#define MAXN 1024000

using namespace std;

vector<int> segment_tree;

inline int join(int p1, int p2) { return p1 + p2; }

void init_segment_tree(int N) {
  int length = (int)(2 * pow(2.0, floor((log((double) N) / log(2.0)) + 1)));
  segment_tree.resize(length, 0);
}

void build_segment_tree(bool A[], int node, int b, int e) {
  if (b == e) segment_tree[node] = A[b] ? 1 : 0;
  else {
    int leftIdx = 2 * node, rightIdx = 2 * node + 1;
    build_segment_tree(A, leftIdx, b, (b + e) / 2);
    build_segment_tree(A, rightIdx, (b + e) / 2 + 1, e);
    segment_tree[node] = join(segment_tree[leftIdx], segment_tree[rightIdx]);
  }
}

int query(bool A[], int node, int b, int e, int i, int j) {
  if (i > e || j < b) return -1;
  if (b >= i && e <= j) return segment_tree[node];

  int p1 = query(A, 2 * node, b, (b + e) / 2, i, j);
  int p2 = query(A, 2 * node + 1, (b + e) / 2 + 1, e, i, j);

  if (p1 == -1) return p2;
  if (p2 == -1) return p1;
  return join(p1, p2);
}

void updateRange(bool A[], int node, int b, int e, int i, int j) {
  if (i > e || j < b) return;
  if (b == e) segment_tree[node] = A[b] ? 1 : 0;
  else {
    int leftIdx = 2 * node, rightIdx = 2 * node + 1;
    if(i <= (b + e) / 2) updateRange(A, leftIdx, b, (b + e) / 2, i, j);
    if(j > (b + e) / 2) updateRange(A, rightIdx, (b + e) / 2 + 1, e, i, j);
    segment_tree[node] = join(segment_tree[leftIdx], segment_tree[rightIdx]);
  }
}

bool land[MAXN];

int main() {
  int t;
  cin >> t;
  for(int u = 1; u <= t; u++) {
    int m; cin >> m;

    string landStr;
    while(m--) {
      string patt; int pt;
      cin >> pt >> patt;
      while(pt--) landStr += patt;
    }
    for(uint i = 0; i < landStr.length(); i++)
      land[i] = (landStr[i] == '1');

    init_segment_tree(landStr.length());
    build_segment_tree(land, 1, 0, landStr.length() - 1);

    cout << "Case " << u << ":" << endl;

    int q; cin >> q;
    char type; int a, b, qCount = 0;
    while(q--) {
      cin >> type >> a >> b;

      if(type == 'S') {
        cout << "Q" << (++qCount) << ": " <<
          query(land, 1, 0, landStr.length() - 1, a, b) << endl;
      } else {
        for(int i = a; i <= b; i++) {
          land[i] = type == 'I' ? !land[i] : type == 'F';
        }
        updateRange(land, 1, 0, landStr.length() - 1, a, b);
      }
    }
  }
  return 0;
}
