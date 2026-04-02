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
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        set<int> s;
        for (auto& p : points) s.insert(p[0]);
        vector<int> xs(s.begin(), s.end());
        int res = 0, i = 0;
        while (i < xs.size()) {
            int start = xs[i];
            res++;
            while (i < xs.size() && xs[i] <= start + w) i++;
        }
        return res;
    }
};
