#include <iostream>
#include <vector>

#define uint unsigned int

#define MAXN 20

using namespace std;

int n, t;
int dur[MAXN];

vector<int> bestSel;
int bestSum = 0;

void selectTracks(int i, vector<int> sel, int sum) {
  if(sum > n) return;
  if(i == t) {
    if(sum > bestSum) { bestSel = sel; bestSum = sum; }
    return;
  }
  sel.push_back(dur[i]);
  selectTracks(i + 1, sel, sum + dur[i]);
  sel.pop_back();
  selectTracks(i + 1, sel, sum);
}

int main() {
  while(cin >> n) {
    cin >> t;
    for(int i = 0; i < t; i++) cin >> dur[i];

    bestSum = 0;
    selectTracks(0, vector<int>(), 0);

    cout << (bestSel[0]);
    for(uint i = 1; i < bestSel.size(); i++)
      cout << " " << (bestSel[i]);
    cout << " sum:" << bestSum << endl;
  }
  return 0;
}