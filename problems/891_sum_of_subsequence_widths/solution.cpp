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
    int sumSubseqWidths(vector<int>& nums) {
        long MOD = 1e9 + 7;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long result = 0, pow2 = 1;
        for (int i = 0; i < n; i++) {
            result = (result + nums[i] * pow2 - nums[n-1-i] * pow2) % MOD;
            pow2 = pow2 * 2 % MOD;
        }
        return (result + MOD) % MOD;
    }
};
