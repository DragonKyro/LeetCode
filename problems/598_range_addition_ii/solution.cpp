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
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int minR = m, minC = n;
        for (auto& op : ops) {
            minR = min(minR, op[0]);
            minC = min(minC, op[1]);
        }
        return minR * minC;
    }
};
