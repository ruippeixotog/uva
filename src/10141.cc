#include <cmath>
#include <iostream>
#include <string>

using namespace std;

int main() {
  int t = 0;
  int n, p;
  while((cin >> n >> p) && n != 0) {
    if(t != 0) cout << endl;

    cin.ignore(80, '\n');
    for(int i = 0; i < n; i++)
      cin.ignore(80, '\n');

    string bestProp;
    int bestReqs = -1;
    double bestPrice = INFINITY;

    while(p--) {
      string prop;
      double price; int reqs;

      getline(cin, prop);
      cin >> price >> reqs;
      cin.ignore(80, '\n');
      for(int i = 0; i < reqs; i++)
        cin.ignore(80, '\n');

      if(reqs > bestReqs || reqs == bestReqs && price < bestPrice) {
        bestProp = prop;
        bestReqs = reqs;
        bestPrice = price;
      }
    }

    cout << "RFP #" << ++t << endl;
    cout << bestProp << endl; 
  }
  return 0;
}