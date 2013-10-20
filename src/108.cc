#include <climits>
#include <iostream>

#define MAXN 100

using namespace std;

int matrix[MAXN + 1][MAXN + 1];

int main() {
  int n; cin >> n;
  for(int i = 0; i <= n; i++) {
    for(int j = 0; j <= n; j++) {
      if(i == 0 || j == 0) { matrix[i][j] = 0; continue; }
      cin >> matrix[i][j];
      matrix[i][j] += matrix[i - 1][j] + matrix[i][j - 1];
      matrix[i][j] -= matrix[i - 1][j - 1];
    }
  }

  int best = INT_MIN;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      for(int fi = i; fi <= n; fi++) {
        for(int fj = j; fj <= n; fj++) {
          best = max(best, matrix[fi][fj]
            - matrix[i - 1][fj] - matrix[fi][j - 1]
            + matrix[i - 1][j - 1]);
        }
      }
    }
  }
  cout << best << endl;
  return 0;
}
