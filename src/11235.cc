#include <cmath>
#include <iostream>
#include <vector>

#define MAXN 100000

using namespace std;

struct Result {
  int max, back, front;
  Result() {}
  Result(int m, int b, int f): max(m), back(b), front(f) {}
};

vector<Result> segment_tree;

Result join(int A[], int b, int e, Result p1, Result p2) {
  Result res;
  res.max = max(p1.max, p2.max);
  if(A[(b + e) / 2] == A[(b + e) / 2 + 1])
    res.max = max(res.max, p1.front + p2.back);

  res.back = p1.back;
  if(A[b] == A[(b + e) / 2 + 1]) res.back += p2.back;
  res.front = p2.front;
  if(A[(b + e) / 2] == A[e]) res.front += p1.front;

  return res;
}

void init_segment_tree(int N) {
  int length = (int)(2 * pow(2.0, floor((log((double) N) / log(2.0)) + 1)));
  segment_tree.resize(length);
}

void build_segment_tree(int A[], int node, int b, int e) {
  if (b == e) segment_tree[node] = Result(1, 1, 1);
  else {
    int leftIdx = 2 * node, rightIdx = 2 * node + 1;
    build_segment_tree(A, leftIdx, b, (b + e) / 2);
    build_segment_tree(A, rightIdx, (b + e) / 2 + 1, e);

    segment_tree[node] =
      reduce(A, b, e, segment_tree[leftIdx], segment_tree[rightIdx]);
  }
}

Result query(int A[], int node, int b, int e, int i, int j) {
  if (i > e || j < b) return Result(-1, -1, -1);
  if (b >= i && e <= j) return segment_tree[node];

  Result p1 = query(A, 2 * node, b, (b + e) / 2, i, j);
  Result p2 = query(A, 2 * node + 1, (b + e) / 2 + 1, e, i, j);

  if (p1.max == -1) return p2;
  if (p2.max == -1) return p1;
  return reduce(A, b, e, p1, p2);
}

int arr[MAXN];

int main() {
  int n, q;
  while(cin >> n && n > 0) {
    cin >> q;
    for(int i = 0; i < n; i++) cin >> arr[i];
    init_segment_tree(n);
    build_segment_tree(arr, 1, 0, n - 1);

    while(q--) {
      int i, j;
      cin >> i >> j;
      cout << query(arr, 1, 0, n - 1, i - 1, j - 1).max << endl;
    }
  }
  return 0;
}
