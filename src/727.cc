#include <iostream>
#include <map>
#include <stack>

using namespace std;

map<char, int> prio;

inline void printPop(stack<char>& s) {
  cout << s.top(); s.pop();
}

int main() {
  prio['('] = 0;
  prio['+'] = prio['-'] = 1;
  prio['*'] = prio['/'] = 2;

  int n; string op;
  cin >> n;
  getline(cin, op); getline(cin, op);

  while(n--) {
    stack<char> ops;

    while(getline(cin, op) && !op.empty()) {
      if(op[0] >= '0' && op[0] <= '9') cout << (op[0] - '0');
      else if(op[0] == '(') ops.push(op[0]);
      else if(op[0] == ')') {
        while(ops.top() != '(') printPop(ops);
        ops.pop();
      }
      else {
        while(!ops.empty() && prio[ops.top()] >= prio[op[0]])
          printPop(ops);
        ops.push(op[0]);
      }
    }
    while(!ops.empty()) printPop(ops);
    cout << endl;
    if(n) cout << endl;
  }
  return 0;
}