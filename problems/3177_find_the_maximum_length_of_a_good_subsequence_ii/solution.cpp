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
    int maximumLength(vector<int>& nums, int k) {
        vector<unordered_map<int,int>> dpVal(k+1);
        vector<int> best(k+1, 0);
        int res = 0;
        for (int x : nums) {
            for (int j = k; j >= 0; j--) {
                int cur = dpVal[j][x] + 1;
                if (j > 0) cur = max(cur, best[j-1] + 1);
                dpVal[j][x] = max(dpVal[j][x], cur);
                best[j] = max(best[j], cur);
                res = max(res, cur);
            }
        }
        return res;
    }
};
