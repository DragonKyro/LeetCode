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
    bool isBoomerang(vector<vector<int>>& points) {
        return (points[1][1] - points[0][1]) * (points[2][0] - points[0][0]) !=
               (points[2][1] - points[0][1]) * (points[1][0] - points[0][0]);
    }
};
