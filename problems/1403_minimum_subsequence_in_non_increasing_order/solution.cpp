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
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        int total = accumulate(nums.begin(), nums.end(), 0);
        vector<int> res;
        int cur = 0;
        for (int n : nums) {
            cur += n;
            res.push_back(n);
            if (cur > total - cur) break;
        }
        return res;
    }
};
