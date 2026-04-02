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
    bool isPathCrossing(string path) {
        set<pair<int,int>> visited;
        int x = 0, y = 0;
        visited.insert({0, 0});
        for (char d : path) {
            if (d == 'N') y++;
            else if (d == 'S') y--;
            else if (d == 'E') x++;
            else x--;
            if (visited.count({x, y})) return true;
            visited.insert({x, y});
        }
        return false;
    }
};
