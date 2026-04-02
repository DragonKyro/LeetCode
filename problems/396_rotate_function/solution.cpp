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
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        long total = 0, f = 0;
        for (int i = 0; i < n; i++) {
            total += nums[i];
            f += (long)i * nums[i];
        }
        long res = f;
        for (int i = 1; i < n; i++) {
            f = f + total - (long)n * nums[n - i];
            res = max(res, f);
        }
        return res;
    }
};
