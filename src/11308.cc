#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>

#define siterator set< pair<int, string> >::iterator

using namespace std;

void toUpper(string& str) {
  transform(str.begin(), str.end(), str.begin(), ::toupper);
}

int main() {
  int t; cin >> t;
  string line; getline(cin, line);

  while(t--) {
    string binder; getline(cin, binder);
    int m, n, b;
    cin >> m >> n >> b;

    map<string, int> ingredients;
    while(m--) {
      pair<string, int> ing;
      cin >> ing.first >> ing.second;
      ingredients.insert(ing);
    }

    set< pair<int, string> > recipes;
    while(n--) {
      getline(cin, line); getline(cin, line);
      int nc; cin >> nc;

      int cost = 0;
      while(nc--) {
        string ingName; int qt;
        cin >> ingName >> qt;
        cost += qt * ingredients[ingName];
      }
      if(cost <= b) recipes.insert(pair<int, string>(cost, line));
    }
    getline(cin, line);

    toUpper(binder);
    cout << binder << endl;
    if(recipes.empty()) cout << "Too expensive!" << endl;
    else {
      for(siterator it = recipes.begin(); it != recipes.end(); it++)
        cout << it->second << endl;
    }
    cout << endl;
  }
  return 0;
}
