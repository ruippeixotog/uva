#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  string letters;
  while(cin >> letters && letters != "#") {
    if(next_permutation(letters.begin(), letters.end()))
      cout << letters << endl;
    else cout << "No Successor" << endl;
  }
  return 0;
}