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
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int> ballColor, colorCount;
        vector<int> res;
        for (auto& q : queries) {
            int ball = q[0], color = q[1];
            if (ballColor.count(ball)) {
                int old = ballColor[ball];
                if (--colorCount[old] == 0) colorCount.erase(old);
            }
            ballColor[ball] = color;
            colorCount[color]++;
            res.push_back(colorCount.size());
        }
        return res;
    }
};
