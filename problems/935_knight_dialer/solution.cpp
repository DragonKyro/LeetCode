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
    int knightDialer(int n) {
        int MOD = 1e9 + 7;
        vector<vector<int>> moves = {{4,6},{6,8},{7,9},{4,8},{0,3,9},{},{0,1,7},{2,6},{1,3},{2,4}};
        vector<long long> dp(10, 1);
        for (int k = 1; k < n; k++) {
            vector<long long> newDp(10, 0);
            for (int i = 0; i < 10; i++)
                for (int j : moves[i])
                    newDp[j] = (newDp[j] + dp[i]) % MOD;
            dp = newDp;
        }
        long long result = 0;
        for (long long v : dp) result = (result + v) % MOD;
        return result;
    }
};
