#include <iostream>
#include <sstream>

#define MAXN 99
#define MAXM 99

using namespace std;

int n, m;
int field[MAXN][MAXM];

int numPools = 0;
int poolSize[MAXN * MAXM / 2];

int floodFill(int i, int j, int pool) {
  if(i < 0 || i >= n || j < 0 || j >= m || field[i][j]) return 0;
  field[i][j] = pool;

  int size = 1;
  for(int di = -1; di <= 1; di++) {
    for(int dj = -1; dj <= 1; dj++) {
      size += floodFill(i + di, j + dj, pool);
    }
  }
  return size;
}

int main() {
  int t; cin >> t;
  string line; getline(cin, line); getline(cin, line);
  while(t--) {
    n = 0;
    while(getline(cin, line) && (line[0] == 'L' || line[0] == 'W')) {
      m = line.length();
      for(int i = 0; i < m; i++)
        field[n][i] = (line[i] == 'W') - 1;
      ++n;
    }

    numPools = 0;
    do {
      stringstream sin(line);
      int row, col; sin >> row >> col;
      if(!field[--row][--col]) {
        numPools++;
        poolSize[numPools] = floodFill(row, col, numPools);
      }
      cout << poolSize[field[row][col]] << endl;

    } while(getline(cin, line) && !line.empty());

    if(t) cout << endl;
  }
  return 0;
}