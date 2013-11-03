#include <algorithm>
#include <iostream>
#include <vector>

#define MAXW 50
#define MAXH 50

using namespace std;

int w, h;
string image[MAXH];

int di[] = {1, 0, -1, 0};
int dj[] = {0, 1, 0, -1};

int floodFill(int i, int j, bool dot) {
  if(i < 0 || i >= h || j < 0 || j >= w) return 0;
  if(dot && image[i][j] != 'X') return 0;
  if(!dot && image[i][j] == '.') return 0;

  int dots = 0;
  if(!dot && image[i][j] == 'X') {
    floodFill(i, j, true);
    ++dots;
  }

  image[i][j] = (dot ? '*' : '.');
  for(int d = 0; d < 4; d++)
    dots += floodFill(i + di[d], j + dj[d], dot);

  return dots;
}

int main() {
  int t = 0;
  while(cin >> w >> h && w > 0) {
    for(int i = 0; i < h; i++) cin >> image[i];

    vector<int> dices;
    for(int i = 0; i < h; i++) {
      for(int j = 0; j < w; j++) {
        if(image[i][j] != '.')
          dices.push_back(floodFill(i, j, false));
      }
    }
    sort(dices.begin(), dices.end());

    cout << "Throw " << ++t << endl;
    cout << dices[0];
    for(int i = 1; i < (int) dices.size(); i++)
      cout << " " << dices[i];
    cout << endl << endl;
  }
  return 0;
}
