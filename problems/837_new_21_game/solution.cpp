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
    double new21Game(int n, int k, int maxPts) {
        if (k == 0 || n >= k + maxPts) return 1.0;
        vector<double> dp(n + 1, 0);
        dp[0] = 1.0;
        double windowSum = 1.0;
        for (int i = 1; i <= n; i++) {
            dp[i] = windowSum / maxPts;
            if (i < k) windowSum += dp[i];
            if (i >= maxPts) windowSum -= dp[i - maxPts];
        }
        double result = 0;
        for (int i = k; i <= n; i++) result += dp[i];
        return result;
    }
};
