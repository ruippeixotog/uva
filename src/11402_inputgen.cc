#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

char ops[] = {'F', 'E', 'I', 'S'};

int main() {
  srand(time(NULL));

  int cases = rand() % 5 + 1;
  cout << cases << endl;

  while(cases--) {
    cout << 1 << endl;

    int t = rand() % 100 + 100;
    cout << t << endl;

    int ssize = rand() % 25 + 25;
    for(int i = 0; i < ssize; i++)
      cout << rand() % 2;
    cout << endl;

    int n = t * ssize;

    int q = rand() % 500 + 500;
    cout << q << endl;

    for(int i = 0; i < q; i++) {
      char op = ops[rand() % 4];
      int a = rand() % n;
      int b = rand() % (n - a) + a;
      cout << op << " " << a << " " << b << endl;
    }
  }
}
