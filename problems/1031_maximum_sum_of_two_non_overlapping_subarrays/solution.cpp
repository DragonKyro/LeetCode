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
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        return max(solve(nums, firstLen, secondLen), solve(nums, secondLen, firstLen));
    }
    int solve(vector<int>& nums, int L, int M) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i+1] = prefix[i] + nums[i];
        int maxL = 0, ans = 0;
        for (int i = L + M; i <= n; i++) {
            maxL = max(maxL, prefix[i - M] - prefix[i - M - L]);
            ans = max(ans, maxL + prefix[i] - prefix[i - M]);
        }
        return ans;
    }
};
