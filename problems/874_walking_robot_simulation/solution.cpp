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
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int,int>> obs;
        for (auto& o : obstacles) obs.insert({o[0], o[1]});
        int dx[] = {0,1,0,-1}, dy[] = {1,0,-1,0};
        int x = 0, y = 0, di = 0, result = 0;
        for (int cmd : commands) {
            if (cmd == -2) di = (di + 3) % 4;
            else if (cmd == -1) di = (di + 1) % 4;
            else for (int i = 0; i < cmd; i++) {
                int nx = x+dx[di], ny = y+dy[di];
                if (!obs.count({nx, ny})) { x = nx; y = ny; result = max(result, x*x+y*y); }
            }
        }
        return result;
    }
};
