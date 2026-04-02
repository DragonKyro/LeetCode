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
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;
        int result = 2;
        for (int i = 0; i < n; i++) {
            map<pair<int,int>, int> slopes;
            for (int j = i + 1; j < n; j++) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                int g = __gcd(abs(dx), abs(dy));
                if (g != 0) { dx /= g; dy /= g; }
                if (dx < 0 || (dx == 0 && dy < 0)) { dx = -dx; dy = -dy; }
                slopes[{dx, dy}]++;
            }
            for (auto& [k, v] : slopes) result = max(result, v + 1);
        }
        return result;
    }
};
