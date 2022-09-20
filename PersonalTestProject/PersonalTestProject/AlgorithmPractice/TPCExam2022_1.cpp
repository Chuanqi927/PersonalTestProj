//
//  TPCExam2022_1.cpp
//  PersonalTestProject
//
//  Created by mortyxiong on 2022/09/20.
//

#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

class Team {
public:
    int n;
    int p;
    int q;
    
    friend bool operator<(const Team& team1, const Team& team2);
};

bool operator< (const Team& team1, const Team& team2) {
    if (team1.p > team2.p) {
        return true;
    }
    else if (team1.p == team2.p &&
             team1.q > team2.q) {
        return true;
    }
    return false;
}

int TPCExam2022_1Tester(int argc, char const *argv[]) {
    int n; // 参赛队伍个数
    int m; // 晋级队伍个数
    cin >> n;
    cin >> m;
    int totalMatches = n * (n-1) / 2;   // 总场次
    vector<Team> teams(n);
    int result[n];  // 每个队伍能否晋级
    for (int i=0; i<totalMatches; i++) {
        int team1, team2, team1WinCount, team2WinCount;
        cin >> team1;
        cin >> team2;
        cin >> team1WinCount;
        cin >> team2WinCount;
        if (team1WinCount > team2WinCount) {
            teams[team1].p++;
        } else {
            teams[team2].p++;
        }
        teams[team1].q+=team1WinCount;
        teams[team2].q+=team2WinCount;
    }
    sort(teams.begin(), teams.end());
    for (int i=0; i<n; ++i) {
        int teamN = teams[i].n;
        if (n-i <= m) {
            result[teamN] = 1;
        }
        else {
            result[teamN] = 0;
        }
    }
    for (int i=0; i<n; ++i) {
        cout << result[i] << endl;
    }
    return 0;
}
