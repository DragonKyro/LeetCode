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
        bitset<100001> dp;
        dp[0] = 1;
        for (int v : vals) {
            bitset<100001> mask;
            for (int i = 0; i < v; i++) mask[i] = 1;
            dp |= (dp & mask) << v;
        }
        for (int i = 2*mx; i >= 0; i--)
            if (dp[i]) return i;
        return 0;
    }
};
