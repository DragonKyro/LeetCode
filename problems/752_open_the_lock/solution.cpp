#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <climits>
#include <queue>
#include <stack>
#include <cmath>
#include <numeric>
#include <set>
#include <map>
using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        if (dead.count("0000")) return -1;
        queue<string> q;
        unordered_set<string> visited;
        q.push("0000"); visited.insert("0000");
        int turns = 0;
        while (!q.empty()) {
            int sz = q.size();
            for (int s = 0; s < sz; s++) {
                string state = q.front(); q.pop();
                if (state == target) return turns;
                for (int i = 0; i < 4; i++) {
                    for (int d : {-1, 1}) {
                        string next = state;
                        next[i] = (state[i] - '0' + d + 10) % 10 + '0';
                        if (!visited.count(next) && !dead.count(next)) {
                            visited.insert(next); q.push(next);
                        }
                    }
                }
            }
            turns++;
        }
        return -1;
    }
};
