#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, d;
  while(cin >> n >> d) {
    vector<int> cont;

    while(d != 1) {
      int e = n / d, rem = n - e * d;
      cont.push_back(e);
      n = d; d = rem;
    }
    cont.push_back(n);

    cout << "[" << cont[0] << ";" << cont[1];
    for(int i = 2; i < cont.size(); i++)
      cout << "," << cont[i];
    cout << "]" << endl;
  }
  return 0;
}