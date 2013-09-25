#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#define uint unsigned int

using namespace std;

struct TeamInfo {
  string name;
  int games[3];
  int goals, goalsAgainst;

  void addResult(int g, int ga) {
    int result = g > ga ? 0 : g == ga ? 1 : 2;
    games[result]++;
    goals += g; goalsAgainst += ga;
  }

  inline int getPoints() const { return games[0] * 3 + games[1]; }
  inline int getGoalDiff() const { return goals - goalsAgainst; }
  inline int getGamesPlayed() const { return games[0] + games[1] + games[2]; }

  TeamInfo(string n): name(n), goals(0), goalsAgainst(0) {
    memset(games, 0, sizeof(games));
  }

  bool operator<(const TeamInfo& other) const {
    int cmp = getPoints() - other.getPoints();
    if(cmp != 0) return cmp < 0;
    cmp = games[0] - other.games[0];
    if(cmp != 0) return cmp < 0;
    cmp = getGoalDiff() - other.getGoalDiff();
    if(cmp != 0) return cmp < 0;
    cmp = goals - other.goals;
    if(cmp != 0) return cmp < 0;
    cmp = other.getGamesPlayed() - getGamesPlayed();
    if(cmp != 0) return cmp < 0;
    return other.name < name;
  }
};

int main() {
  int n, t;
  scanf("%d\n", &n);
  while(n--) {
    string tournament;
    getline(cin, tournament);

    vector<TeamInfo> teams;
    map<string, int> nameMap;

    scanf("%d\n", &t);
    for(int i = 0; i < t; i++) {
      string teamName;
      getline(cin, teamName);
      teams.push_back(TeamInfo(teamName));
      nameMap[teamName] = i;
    }

    scanf("%d\n", &t);
    while(t--) {
      string teamA, teamB;
      int goalsA, goalsB;
      getline(cin, teamA, '#');
      scanf("%d@%d#", &goalsA, &goalsB);
      getline(cin, teamB);

      teams[nameMap[teamA]].addResult(goalsA, goalsB);
      teams[nameMap[teamB]].addResult(goalsB, goalsA);
    }

    sort(teams.rbegin(), teams.rend());

    cout << tournament << endl;
    for(uint i = 0; i < teams.size(); i++) {
      TeamInfo t = teams[i];  
      printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",
        i + 1, t.name.c_str(), t.getPoints(), t.getGamesPlayed(),
        t.games[0], t.games[1], t.games[2],
        t.getGoalDiff(), t.goals, t.goalsAgainst);
    }

    if(n) cout << endl;
  }
  return 0;
}