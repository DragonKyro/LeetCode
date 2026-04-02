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
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result(n, -1);
        int window = 2 * k + 1;
        if (window > n) return result;
        long long sum = 0;
        for (int i = 0; i < window; i++) sum += nums[i];
        result[k] = sum / window;
        for (int i = k + 1; i < n - k; i++) {
            sum += nums[i + k] - nums[i - k - 1];
            result[i] = sum / window;
        }
        return result;
    }
};
