#include <cstring>
#include <iostream>
#include <sstream>

#define MAXN 99

using namespace std;

int n;
int square[MAXN][MAXN];

bool found[MAXN];

int di[] = {1, 0, -1, 0};
int dj[] = {0, 1, 0, -1};

void floodFill(int i, int j, int value) {
  if(i < 0 || i >= n || j < 0 || j >= n || square[i][j] != value)
    return;

  square[i][j] = -1;
  for(int d = 0; d < 4; d++)
    floodFill(i + di[d], j + dj[d], value);
}

int main() {
  while(cin >> n && n > 0) {
    string line; getline(cin, line);

    memset(square, 0, sizeof square);
    for(int i = 1; i < n; i++) {
      getline(cin, line); stringstream sin(line);
      int pi, pj;
      while(sin >> pi >> pj) square[--pi][--pj] = i;
    }

    memset(found, false, n * sizeof(bool));
    bool fail = false;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        int cell = square[i][j];
        if(cell == -1) continue;
        if(found[cell]) { fail = true; break; }
        found[cell] = true;
        floodFill(i, j, square[i][j]);
      }
      if(fail) break;
    }
    cout << (fail ? "wrong" : "good") << endl; 
  }
  return 0;
}
