#include <cmath>
#include <iostream>
#include <vector>

#define uint unsigned int

#define MAXN 1024000

using namespace std;

vector<int> segment_tree;
vector<bool> has_lazy_update;
vector<char> lazy_op;

void addLazyOp(char op, int node, int b, int e) {

  if(op == 'I') segment_tree[node] = (e - b + 1) - segment_tree[node];
  else segment_tree[node] = (op == 'F' ? e - b + 1 : 0);
  if(b == e) return;

  if(!has_lazy_update[node]) {
    has_lazy_update[node] = true;
    lazy_op[node] = op;
  } else {
    if(op == 'F' || op == 'E') lazy_op[node] = op;
    else if(lazy_op[node] == 'I') has_lazy_update[node] = false;
    else lazy_op[node] = (lazy_op[node] == 'F' ? 'E' : 'F');
  }
}

inline int join(int p1, int p2) { return p1 + p2; }

void init_segment_tree(int N) {
  int length = (int)(2 * pow(2.0, floor((log((double) N) / log(2.0)) + 1)));
  segment_tree.resize(length, 0);
  has_lazy_update.resize(length, false);
  lazy_op.resize(length);
}

void build_segment_tree(bool A[], int node, int b, int e) {
  if (b == e) segment_tree[node] = A[b] ? 1 : 0;
  else {
    int leftIdx = 2 * node, rightIdx = 2 * node + 1;
    build_segment_tree(A, leftIdx, b, (b + e) / 2);
    build_segment_tree(A, rightIdx, (b + e) / 2 + 1, e);
    segment_tree[node] = join(segment_tree[leftIdx], segment_tree[rightIdx]);
    has_lazy_update[node] = false;
  }
}

void update_range(char op, bool A[], int node, int b, int e, int i, int j) {
  if (i > e || j < b) return;
  if (b >= i && e <= j) addLazyOp(op, node, b, e);
  else {
    int leftIdx = 2 * node, rightIdx = 2 * node + 1;

    if(has_lazy_update[node]) {
      update_range(lazy_op[node], A, leftIdx, b, (b + e) / 2, b, e);
      update_range(lazy_op[node], A, rightIdx, (b + e) / 2 + 1, e, b, e);
      has_lazy_update[node] = false;
    }

    if(i <= (b + e) / 2) update_range(op, A, leftIdx, b, (b + e) / 2, i, j);
    if(j > (b + e) / 2) update_range(op, A, rightIdx, (b + e) / 2 + 1, e, i, j);
    segment_tree[node] = join(segment_tree[leftIdx], segment_tree[rightIdx]);
  }
}

int query(bool A[], int node, int b, int e, int i, int j) {
  if (i > e || j < b) return -1;
  if (b >= i && e <= j) return segment_tree[node];

  if(has_lazy_update[node]) {
    update_range(lazy_op[node], A, 2 * node, b, (b + e) / 2, b, e);
    update_range(lazy_op[node], A, 2 * node + 1, (b + e) / 2 + 1, e, b, e);
    has_lazy_update[node] = false;
  }

  int p1 = query(A, 2 * node, b, (b + e) / 2, i, j);
  int p2 = query(A, 2 * node + 1, (b + e) / 2 + 1, e, i, j);

  if (p1 == -1) return p2;
  if (p2 == -1) return p1;
  return join(p1, p2);
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
    char op; int a, b, qCount = 0;
    while(q--) {
      cin >> op >> a >> b;

      if(op == 'S') {
        cout << "Q" << (++qCount) << ": " <<
          query(land, 1, 0, landStr.length() - 1, a, b) << endl;
      } else {
        update_range(op, land, 1, 0, landStr.length() - 1, a, b);
      }
    }
  }
  return 0;
}
