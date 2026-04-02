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
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> suffix(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) suffix[i] = suffix[i + 1] + piles[i];
        vector<vector<int>> memo(n, vector<int>(n + 1, -1));
        function<int(int, int)> dp = [&](int i, int m) -> int {
            if (i >= n) return 0;
            if (2 * m >= n - i) return suffix[i];
            if (memo[i][m] != -1) return memo[i][m];
            int best = 0;
            for (int x = 1; x <= 2 * m; x++) {
                best = max(best, suffix[i] - dp(i + x, max(m, x)));
            }
            return memo[i][m] = best;
        };
        return dp(0, 1);
    }
};
