#include <iostream>
#include <map>

using namespace std;

int main() {
  map<string, int> freq;

  string line;
  getline(cin, line);

  string country;
  while(cin >> country) {
    getline(cin, line);
    freq[country]++;
  }

  for(map<string, int>::iterator it = freq.begin(); it != freq.end(); it++)
    cout << it->first << " " << it->second << endl;

  return 0;
}
