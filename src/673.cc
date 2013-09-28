#include <iostream>
#include <stack>

#define uint unsigned int

using namespace std;

bool match(stack<char>& s, char top) {
  if(s.empty() || s.top() != top) return false;
  else { s.pop(); return true; }
}

int main() {
  int n;
  cin >> n;

  string line;
  getline(cin, line);

  while(n--) {
    getline(cin, line);

    stack<char> s;
    bool valid = true;
    for(uint i = 0; i < line.length() && valid; i++) {
      switch(line[i]) {
        case '(':
        case '[': s.push(line[i]); break;
        case ')': valid = valid && match(s, '('); break;
        case ']': valid = valid && match(s, '['); break;
      }
    }
    valid = valid && s.empty();
    cout << (valid ? "Yes" : "No") << endl;
  }
  return 0;
}