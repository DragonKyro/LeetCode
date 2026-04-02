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
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        set<pair<int,int>> blockedSet;
        for (auto& b : blocked) blockedSet.insert({b[0], b[1]});
        int limit = blocked.size() * (blocked.size() - 1) / 2;
        return bfs(blockedSet, source, target, limit) && bfs(blockedSet, target, source, limit);
    }
    bool bfs(set<pair<int,int>>& blocked, vector<int>& start, vector<int>& end, int limit) {
        queue<pair<int,int>> q;
        set<pair<int,int>> visited;
        q.push({start[0], start[1]});
        visited.insert({start[0], start[1]});
        int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        while (!q.empty()) {
            if ((int)visited.size() > limit) return true;
            auto [r, c] = q.front(); q.pop();
            if (r == end[0] && c == end[1]) return true;
            for (auto& d : dirs) {
                int nr = r+d[0], nc = c+d[1];
                if (nr >= 0 && nr < 1000000 && nc >= 0 && nc < 1000000 && !blocked.count({nr,nc}) && !visited.count({nr,nc})) {
                    visited.insert({nr, nc});
                    q.push({nr, nc});
                }
            }
        }
        return false;
    }
};
