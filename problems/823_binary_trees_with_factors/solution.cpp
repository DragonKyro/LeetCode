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
    int numFactoredBinaryTrees(vector<int>& arr) {
        long MOD = 1e9 + 7;
        sort(arr.begin(), arr.end());
        unordered_map<int, long> dp;
        for (int x : arr) {
            dp[x] = 1;
            for (int y : arr) {
                if ((long)y * y > x) break;
                if (x % y == 0 && dp.count(x / y)) {
                    if (y == x / y) dp[x] = (dp[x] + dp[y] * dp[y]) % MOD;
                    else dp[x] = (dp[x] + 2 * dp[y] % MOD * dp[x / y]) % MOD;
                }
            }
        }
        long res = 0;
        for (auto& [k, v] : dp) res = (res + v) % MOD;
        return res;
    }
};
