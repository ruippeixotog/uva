#include <iostream>
#include <map>
#include <string>

#define uint unsigned int

#define MAXL 100
#define MAXW 100

using namespace std;

struct Node {
  int wordIdx;
  map<char, Node> children;

  Node(): wordIdx(-1) {}

  void add(string word, int idx, uint pos = 0) {
    if(pos == word.length()) wordIdx = idx;
    else children[word[pos]].add(word, idx, pos + 1);
  }
};

struct Pos {
  int bi, bj, ei, ej;
  Pos(): bi(-1), bj(-1), ei(-1), ej(-1) {}
  Pos(int _bi, int _bj, int _ei, int _ej): bi(_bi), bj(_bj), ei(_ei), ej(_ej) {}
};

string matrix[MAXL];
int l;

Node trie;
Pos position[MAXW];

void findAll(Node& n, int i0, int j0, int i, int j, int di, int dj) {
  if(n.wordIdx >= 0) position[n.wordIdx] = Pos(i0, j0, i - di, j - dj);
  if(i < 0 || j < 0 || i >= l || j >= l) return;
  if(n.children.count(matrix[i][j]))
    findAll(n.children[matrix[i][j]], i0, j0, i + di, j + dj, di, dj);
}

int main() {
  cin >> l;

  for(int i = 0; i < l; i++)
    cin >> matrix[i];

  string word;
  int wordIdx = 0;
  while(cin >> word && word != "0")
    trie.add(word, wordIdx++);

  for(int i = 0; i < l; i++) {
    for(int j = 0; j < l; j++) {
      for(int di = -1; di <= 1; di++) {
        for(int dj = -1; dj <= 1; dj++) {
          findAll(trie, i, j, i, j, di, dj);
        }
      }
    }
  }

  for(int i = 0; i < wordIdx; i++) {
    if(position[i].bi < 0) cout << "Not found" << endl;
    else cout << (position[i].bi + 1) << "," << (position[i].bj + 1) << " " <<
      (position[i].ei + 1) << "," << (position[i].ej + 1) << endl;
  }
  return 0;
}
