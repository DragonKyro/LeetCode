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
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        unordered_map<char, vector<int>> m;
        for (int i = 0; i < points.size(); i++)
            m[s[i]].push_back(max(abs(points[i][0]), abs(points[i][1])));
        int limit = INT_MAX;
        for (auto& [c, v] : m) {
            sort(v.begin(), v.end());
            if (v.size() >= 2) limit = min(limit, v[1]);
        }
        int res = 0;
        for (auto& [c, v] : m)
            if (v[0] < limit) res++;
        return res;
    }
};
