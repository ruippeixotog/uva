#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

#define uint unsigned int

#define NMAX 10000
#define HMAX 100
#define MAXT 600

using namespace std;

int main() {
  int t;
  cin >> t;

  string line;
  getline(cin, line);

  while(t--) {
    getline(cin, line);
    getline(cin, line);
    stringstream sin(line);

    cerr << "LINE IS " << line << endl;

    vector<int> indices;
    int idx;
    while(sin >> idx)
      indices.push_back(idx - 1);

    vector<string> values(indices.size());
    string value;
    for(uint i = 0; i < indices.size(); i++) {
      cin >> value;
      values[indices[i]] = value;
    }

    for(uint i = 0; i < values.size(); i++)
      cout << values[i] << endl;

    if(t) {
      getline(cin, line);
      cout << endl;
    }
  }
  return 0;
}
