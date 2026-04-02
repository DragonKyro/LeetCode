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
    int minStickers(vector<string>& stickers, string target) {
        int n = target.size(), N = 1 << n;
        vector<int> dp(N, INT_MAX);
        dp[0] = 0;
        for (int mask = 0; mask < N; mask++) {
            if (dp[mask] == INT_MAX) continue;
            for (auto& sticker : stickers) {
                int cur = mask;
                for (char c : sticker) {
                    for (int i = 0; i < n; i++) {
                        if ((cur >> i) & 1) continue;
                        if (target[i] == c) { cur |= (1 << i); break; }
                    }
                }
                dp[cur] = min(dp[cur], dp[mask] + 1);
            }
        }
        return dp[N-1] == INT_MAX ? -1 : dp[N-1];
    }
};
