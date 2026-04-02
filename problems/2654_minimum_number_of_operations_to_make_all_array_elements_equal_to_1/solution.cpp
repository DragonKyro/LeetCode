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
    int minOperations(vector<int>& nums) {
        int n = nums.size(), g = 0;
        for (int x : nums) g = __gcd(g, x);
        if (g > 1) return -1;
        int ans = n - 1;
        for (int i = 0; i < n; i++) {
            int gg = nums[i];
            for (int j = i+1; j < n; j++) {
                gg = __gcd(gg, nums[j]);
                if (gg == 1) { ans = min(ans, j-i+n-2); break; }
            }
        }
        return ans;
    }
};
