#include <iostream>
#include <map>
#include <vector>

#define uint unsigned int

using namespace std;

struct ArrayInfo {
  int base;
  int elemSize;
  vector< pair<uint, uint> > dims;
};

int main() {
  int N, R;
  cin >> N >> R;

  map<string, ArrayInfo> table;
  for(int i = 0; i < N; i++) {
    string name;
    ArrayInfo info;
    int nDims;
    cin >> name >> info.base >> info.elemSize >> nDims;
    while(nDims--) {
      pair<int, int> bounds;
      cin >> bounds.first >> bounds.second;
      info.dims.push_back(bounds);
    }
    int step = info.elemSize;
    for(int i = info.dims.size() - 1; i >= 0; i--) {
      int newStep = step * (info.dims[i].second - info.dims[i].first + 1);
      info.dims[i].second = step;
      step = newStep;
    }
    table.insert(pair<string, ArrayInfo>(name, info));
  }

  for(int i = 0; i < R; i++) {
    string name;
    cin >> name;
    ArrayInfo info = table.find(name)->second;
    cout << name << "[";

    int address = info.base;
    for(uint j = 0; j < info.dims.size(); j++) {
      int dimIdx;
      cin >> dimIdx;
      address += (dimIdx - info.dims[j].first) * info.dims[j].second;

      if(j != 0) cout << ", ";
      cout << dimIdx;
    }

    cout << "] = " << address << endl;
  }
  return 0;
}