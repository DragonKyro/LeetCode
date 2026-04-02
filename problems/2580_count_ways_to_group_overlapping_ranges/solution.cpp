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
    int countWays(vector<vector<int>>& ranges) {
        sort(ranges.begin(), ranges.end());
        long long MOD = 1e9+7;
        int groups = 0, end = -1;
        for (auto& r : ranges) { if (r[0] > end) groups++; end = max(end, r[1]); }
        long long ans = 1;
        for (int i = 0; i < groups; i++) ans = ans * 2 % MOD;
        return ans;
    }
};
