#include <algorithm>
#include <iostream>
#include <string>

#define P 12

using namespace std;

bool state[P];

int findBest(int pieces) {
  int best = pieces;
  for(int i = 0; i < P - 1; i++) {
    if(state[i] && state[i + 1]) {
      state[i] = state[i + 1] = false;
      if(i > 0 && !state[i - 1]) {
        state[i - 1] = true;
        best = min(best, findBest(pieces - 1));
        state[i - 1] = false;
      }
      if(i + 2 < P && !state[i + 2]) {
        state[i + 2] = true;
        best = min(best, findBest(pieces - 1));
        state[i + 2] = false;
      }
      state[i] = state[i + 1] = true;
    }
  }
  return best;
}

int main() {
  int n; cin >> n;

  while(n--) {
    string game; cin >> game;

    int pieces = 0;
    for(int i = 0; i < P; i++) {
      state[i] = game[i] == 'o';
      if(state[i]) pieces++;
    }
    cout << findBest(pieces) << endl;
  }
  return 0;
}
