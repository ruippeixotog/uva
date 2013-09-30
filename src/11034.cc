#include <iostream>
#include <queue>

using namespace std;

int main() {
  int c, l, m;
  cin >> c;

  while(c--) {
    cin >> l >> m;
    l *= 100;

    queue<int> left, right;
    while(m--) {
      int ni; string si;
      cin >> ni >> si;
      (si == "left" ? left : right).push(ni);
    }

    int count = 0;
    bool inLeft = true;
    while(!left.empty() || !right.empty()) {
      queue<int>& curr = (inLeft ? left : right);

      int len = 0;
      while(!curr.empty() && len + curr.front() <= l) {
        len += curr.front(); curr.pop();
      }
      count++;
      inLeft = !inLeft;
    }
    cout << count << endl;
  }
  return 0;
}
