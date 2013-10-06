#include <cmath>
#include <iostream>
#include <vector>
#include <utility>

#define MAXN 500

using namespace std;

vector< pair<int, int> > segment_tree;

pair<int, int> join(pair<int, int> p1, pair<int, int> p2) {
  return make_pair(min(p1.first, p2.first), max(p1.second, p2.second));
}

void init_segment_tree(int N) {
  int length = (int)(2 * pow(2.0, floor((log((double) N) / log(2.0)) + 1)));
  segment_tree.resize(length);
}

void build_segment_tree(int A[][MAXN], int node, int bx, int by, int ex, int ey) {
  if (by == ey) {
    if(bx == ex) segment_tree[node] = make_pair(A[bx][by], A[bx][by]);
    else {
      int leftIdx = 2 * node, rightIdx = 2 * node + 1;
      build_segment_tree(A, leftIdx, bx, by, (bx + ex) / 2, ey);
      build_segment_tree(A, rightIdx, (bx + ex) / 2 + 1, by, ex, ey);
      segment_tree[node] = join(segment_tree[leftIdx], segment_tree[rightIdx]);
    }
  } else {
    int leftIdx = 2 * node, rightIdx = 2 * node + 1;
    build_segment_tree(A, leftIdx, bx, by, ex, (by + ey) / 2);
    build_segment_tree(A, rightIdx, bx, (by + ey) / 2 + 1, ex, ey);
    segment_tree[node] = join(segment_tree[leftIdx], segment_tree[rightIdx]);
  }
}

pair<int, int> query(int A[][MAXN], int node, int bx, int by, int ex, int ey,
  int ix, int iy, int jx, int jy) {

  if (ix > ex || jx < bx || iy > ey || jy < by) return make_pair(-1, -1);
  if (bx >= ix && ex <= jx && by >= iy && ey <= jy) return segment_tree[node];

  pair<int, int> p1, p2;
  if(by == ey) {
    p1 = query(A, 2 * node, bx, by, (bx + ex) / 2, ey, ix, iy, jx, jy);
    p2 = query(A, 2 * node + 1, (bx + ex) / 2 + 1, by, ex, ey, ix, iy, jx, jy);
  } else {
    p1 = query(A, 2 * node, bx, by, ex, (by + ey) / 2, ix, iy, jx, jy);
    p2 = query(A, 2 * node + 1, bx, (by + ey) / 2 + 1, ex, ey, ix, iy, jx, jy);
  }

  if (p1.first == -1) return p2;
  if (p2.first == -1) return p1;
  return join(p1, p2);
}

void update(int A[][MAXN], int node, int bx, int by, int ex, int ey,
  int ix, int iy) {
  if (by == ey) {
    if(bx == ex) segment_tree[node] = make_pair(A[bx][by], A[bx][by]);
    else {
      int leftIdx = 2 * node, rightIdx = 2 * node + 1;
      if(ix <= (bx + ex) / 2)
        update(A, leftIdx, bx, by, (bx + ex) / 2, ey, ix, iy);
      else update(A, rightIdx, (bx + ex) / 2 + 1, by, ex, ey, ix, iy);
      segment_tree[node] = join(segment_tree[leftIdx], segment_tree[rightIdx]);
    }
  } else {
    int leftIdx = 2 * node, rightIdx = 2 * node + 1;
    if(iy <= (by + ey) / 2)
      update(A, leftIdx, bx, by, ex, (by + ey) / 2, ix, iy);
    else update(A, rightIdx, bx, (by + ey) / 2 + 1, ex, ey, ix, iy);
    segment_tree[node] = join(segment_tree[leftIdx], segment_tree[rightIdx]);
  }
}

int arr[MAXN][MAXN];

int main() {
  int n, q; string line;
  cin >> n;
  getline(cin, line);

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> arr[i][j];
    }
  }

  init_segment_tree(n * n);
  build_segment_tree(arr, 1, 0, 0, n - 1, n - 1);

  cin >> q;
  char type; int arg[4];
  while(cin >> type) {
    if(type == 'q') {
      cin >> arg[0] >> arg[1] >> arg[2] >> arg[3];
      pair<int, int> res = query(arr, 1, 0, 0, n - 1, n - 1,
        arg[0] - 1, arg[1] - 1, arg[2] - 1, arg[3] - 1);
      cout << res.second << " " << res.first << endl;
      
    } else {
      cin >> arg[0] >> arg[1] >> arg[2];
      arr[--arg[0]][--arg[1]] = arg[2];
      update(arr, 1, 0, 0, n - 1, n - 1, arg[0], arg[1]);
    }
  }
  return 0;
}
