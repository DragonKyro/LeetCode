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
    long long maximumTotalDamage(vector<int>& power) {
        map<int, long long> cnt;
        for (int p : power) cnt[p]++;
        vector<int> vals;
        for (auto& [k,v] : cnt) vals.push_back(k);
        int n = vals.size();
        vector<long long> dp(n+1, 0);
        int j = 0;
        for (int i = 0; i < n; i++) {
            dp[i+1] = dp[i];
            while (j < i && vals[j] < vals[i] - 2) j++;
            dp[i+1] = max(dp[i+1], dp[j] + (long long)vals[i] * cnt[vals[i]]);
        }
        return dp[n];
    }
};
