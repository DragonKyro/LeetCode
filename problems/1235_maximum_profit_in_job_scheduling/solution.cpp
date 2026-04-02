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
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<array<int,3>> jobs(n);
        for (int i = 0; i < n; i++) jobs[i] = {endTime[i], startTime[i], profit[i]};
        sort(jobs.begin(), jobs.end());
        vector<int> dp(n+1, 0);
        vector<int> ends;
        for (auto& j : jobs) ends.push_back(j[0]);
        for (int i = 1; i <= n; i++) {
            int s = jobs[i-1][1];
            int j = upper_bound(ends.begin(), ends.begin()+i, s) - ends.begin();
            dp[i] = max(dp[i-1], dp[j] + jobs[i-1][2]);
        }
        return dp[n];
    }
};
