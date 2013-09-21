#include <algorithm>
#include <cstdio>

using namespace std;

char grid[3][4];

char getWinner() {
  char winRow[3], winCol[3], winDiag[2];

  winDiag[0] = grid[0][0];
  winDiag[1] = grid[0][2];

  // get the winner of each row, column and diagonal
  for(int i = 0; i < 3; i++) {
    winRow[i] = grid[i][0];
    winCol[i] = grid[0][i];

    for(int j = 1; j < 3; j++) {
      if(winRow[i] != grid[i][j]) winRow[i] = '.';
      if(winCol[i] != grid[j][i]) winCol[i] = '.';
    }

    if(winDiag[0] != grid[i][i]) winDiag[0] = '.';
    if(winDiag[1] != grid[i][2 - i]) winDiag[1] = '.';
  }

  sort(winRow, winRow + 3);
  sort(winCol, winCol + 3);

  // check if there is more than one "winner" row or more than one
  // "winner" column
  if(winRow[1] != '.' || winCol[1] != '.') return 0;

  char winner = winRow[2];

  if(winner != '.') {
    if(winCol[2] != '.' && winner != winCol[2]) return 0;
  } else {
    winner = winCol[2];
  }

  if(winner != '.') {
    if(winDiag[0] != '.' && winner != winDiag[0]) return 0;
    if(winDiag[1] != '.' && winner != winDiag[1]) return 0;
  } else {
    if(winDiag[0] != '.') {
      if(winDiag[1] != '.' && winDiag[0] != winDiag[1]) return 0;
      winner = winDiag[0];
    } else {
      winner = winDiag[1];
    }
  }

  return winner;
}

int main() {
  int t;
  scanf("%d\n", &t);

  while(t--) {
    for(int i = 0; i < 3; i++)
      scanf("%s\n", grid[i]);

    int countX = 0, countO = 0;
    for(int i = 0; i < 3; i++) {
      for(int j = 0; j < 3; j++) {
        if(grid[i][j] == 'X') countX++;
        else if(grid[i][j] == 'O') countO++;
      }
    }

    if(countX != countO && countX != countO + 1) {
      printf("no\n");
      continue;
    }

    char winner = getWinner();
    bool oTurn = countX == countO + 1;
    bool xTurn = countX == countO;

    bool valid =
      winner == '.' && oTurn ^ xTurn ||
      winner == 'O' && xTurn ||
      winner == 'X' && oTurn;

    printf("%s\n", valid ? "yes" : "no");
  }
  return 0;
}
