#include <cstring>
#include <iostream>

#define V 5
#define E 8

using namespace std;

int degree[] = {3, 3, 4, 2, 4};
int adjs[5][4] = {
  {1, 2, 4, -1},
  {0, 2, 4, -1},
  {0, 1, 3, 4},
  {2, 4, -1, -1},
  {0, 1, 2, 3}
};

bool used[V][V];
char solution[E];

void search(int curr, int step) {
  if(step > E)
    cout << string(solution) << endl;
  else for(int i = 0; i < degree[curr]; i++) {
    int adj = adjs[curr][i];
    if(!used[curr][adj]) {
      used[curr][adj] = used[adj][curr] = true;
      solution[step] = adj + '1';
      search(adj, step + 1);
      used[curr][adj] = used[adj][curr] = false;
    }
  }
}

int main() {
  memset(used, 0, sizeof(used));
  solution[0] = '1';
  search(0, 1);
  return 0;
}