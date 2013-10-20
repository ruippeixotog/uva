#include <algorithm>
#include <climits>
#include <iostream>

#define MAXN 75

using namespace std;

int matrix[2 * MAXN + 1][2 * MAXN + 1];

int main() {
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    for(int i = 0; i < 2 * n; i++) {
      for(int j = 0; j < 2 * n; j++) {
        if(i == 0 || j == 0) { matrix[i][j] = 0; continue; }
        if(i <= n && j <= n) {
          cin >> matrix[i][j];
          matrix[i + n][j] = matrix[i][j + n] =
            matrix[i + n][j + n] = matrix[i][j];
        }
        matrix[i][j] += matrix[i - 1][j] + matrix[i][j - 1];
        matrix[i][j] -= matrix[i - 1][j - 1];
      }
    }

    int best = INT_MIN;
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= n; j++) {
        for(int fi = i; fi < i + n; fi++) {
          for(int fj = j; fj < j + n; fj++) {
            best = max(best, matrix[fi][fj]
              - matrix[i - 1][fj] - matrix[fi][j - 1]
              + matrix[i - 1][j - 1]);
          }
        }
      }
    }
    cout << best << endl;
  }
  return 0;
}