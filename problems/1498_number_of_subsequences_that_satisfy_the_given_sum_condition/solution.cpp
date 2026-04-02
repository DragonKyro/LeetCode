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
    int numSubseq(vector<int>& nums, int target) {
        int MOD = 1e9 + 7;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> pow2(n);
        pow2[0] = 1;
        for (int i = 1; i < n; i++) pow2[i] = (long long)pow2[i-1] * 2 % MOD;
        int res = 0, left = 0, right = n - 1;
        while (left <= right) {
            if (nums[left] + nums[right] > target) right--;
            else { res = (res + pow2[right - left]) % MOD; left++; }
        }
        return res;
    }
};
