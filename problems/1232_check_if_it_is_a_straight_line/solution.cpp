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
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int x0 = coordinates[0][0], y0 = coordinates[0][1];
        int x1 = coordinates[1][0], y1 = coordinates[1][1];
        for (int i = 2; i < (int)coordinates.size(); i++) {
            int x = coordinates[i][0], y = coordinates[i][1];
            if ((long long)(y1-y0)*(x-x0) != (long long)(y-y0)*(x1-x0)) return false;
        }
        return true;
    }
};
