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
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        double res = 1e18;
        int n = nums.size();
        for (int i = 0; i < n/2; i++)
            res = min(res, (nums[i]+nums[n-1-i]) / 2.0);
        return res;
    }
};
