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
    int maximizeWin(vector<int>& pos, int k) {
        int n = pos.size(), ans = 0, j = 0;
        vector<int> dp(n+1, 0);
        for (int i = 0; i < n; i++) {
            while (pos[i]-pos[j] > k) j++;
            dp[i+1] = max(dp[i], i-j+1);
            ans = max(ans, i-j+1+dp[j]);
        }
        return ans;
    }
};
