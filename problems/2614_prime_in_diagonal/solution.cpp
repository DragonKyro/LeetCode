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
    int diagonalPrime(vector<vector<int>>& nums) {
        int n = nums.size(), ans = 0;
        auto isP = [](int n) { if (n<2) return false; for (int i=2;i*i<=n;i++) if (n%i==0) return false; return true; };
        for (int i = 0; i < n; i++) {
            if (isP(nums[i][i])) ans = max(ans, nums[i][i]);
            if (isP(nums[i][n-1-i])) ans = max(ans, nums[i][n-1-i]);
        }
        return ans;
    }
};
