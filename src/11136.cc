#include <iostream>
#include <set>

using namespace std;

int main() {
  int d;
  while(cin >> d && d > 0) {
    multiset<int> tickets;
    int cost = 0;

    int n, v;
    while(d--) {
      cin >> n;
      while(n--) { cin >> v; tickets.insert(v); }

      cost += *(--tickets.end());
      tickets.erase(--tickets.end());
      cost -= *tickets.begin();
      tickets.erase(tickets.begin());
    }
    cout << cost << endl;
  }
  return 0;
}
