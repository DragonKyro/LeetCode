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
    int maxTotalReward(vector<int>& rewardValues) {
        set<int> s(rewardValues.begin(), rewardValues.end());
        vector<int> vals(s.begin(), s.end());
        int mx = vals.back();
        vector<bool> dp(2*mx, false);
        dp[0] = true;
        for (int v : vals)
            for (int x = v-1; x >= 0; x--)
                if (dp[x]) dp[x+v] = true;
        for (int i = 2*mx-1; i >= 0; i--)
            if (dp[i]) return i;
        return 0;
    }
};
