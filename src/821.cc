#include <cstdio>
#include <iostream>

#define MAXP 100
#define INF 999999

using namespace std;

int graph[MAXP][MAXP];

int main() {
  int t = 0, a, b;
  while(cin >> a >> b && a != 0) {
    for(int i = 0; i < MAXP; i++) {
      for(int j = 0; j < MAXP; j++) {
        graph[i][j] = INF;
      }
    }

    int p = 0;
    do { p = max(p, max(a, b)); graph[--a][--b] = 1; }
    while(cin >> a >> b && a != 0);

    for(int k = 0; k < p; k++) {
      for(int i = 0; i < p; i++) {
        for(int j = 0; j < p; j++) {
            graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
        }
      }
    }

    double sum = 0.0;
    int count = 0;
    for(int i = 0; i < p; i++) {
      for(int j = 0; j < p; j++) {
        if(i != j && graph[i][j] != INF) {
          count++; sum += graph[i][j];
        }
      }
    }
    sum /= count;
    printf("Case %d: average length between pages = %.3f clicks\n", ++t, sum);
  }
  return 0;
}