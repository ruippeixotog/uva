#include <cstdio>
#include <cstring>

#define uint unsigned int

#define TSIZE 8

using namespace std;

int sol[TSIZE];
int numSols;

bool rowUsed[TSIZE];
bool upDiagUsed[TSIZE * 2 - 1];
bool downDiagUsed[TSIZE * 2 - 1];

bool isValid(int col, int row) {
  return !rowUsed[row] && !upDiagUsed[col + row] &&
    !downDiagUsed[col - row + TSIZE - 1];
}

void setQueen(int col, int row, bool pos) {
  rowUsed[row] = upDiagUsed[col + row] =
    downDiagUsed[col - row + TSIZE - 1] = pos;
}

void queens(int first, int col = 0) {
  if(col == TSIZE) {
    printf("%2d      ", ++numSols);
    printf("%d", sol[0] + 1);
    for(int i = 1; i < TSIZE; i++)
      printf(" %d", sol[i] + 1);
    printf("\n");
    return;
  }
  if(col != first) {
    for(int row = 0; row < TSIZE; row++) {
      if(isValid(col, row)) {
        sol[col] = row;
        setQueen(col, row, true);
        queens(first, col + 1);
        setQueen(col, row, false);
      }
    }
  } else queens(first, col + 1);
}

int main() {
  int n;
  scanf("%d", &n);
  while(n--) {
    printf("SOLN       COLUMN\n");
    printf(" #      1 2 3 4 5 6 7 8\n\n");

    numSols = 0;
    memset(rowUsed, 0, sizeof(rowUsed));
    memset(upDiagUsed, 0, sizeof(upDiagUsed));
    memset(downDiagUsed, 0, sizeof(downDiagUsed));

    int fRow, fCol; scanf("%d %d", &fRow, &fCol);
    sol[--fCol] = --fRow;
    setQueen(fCol, fRow, true);
    queens(fCol);

    if(n) printf("\n");
  }
  return 0;
}