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
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        int m = 0;
        while (dp[m][k] < n) {
            m++;
            for (int j = 1; j <= k; j++)
                dp[m][j] = dp[m-1][j-1] + dp[m-1][j] + 1;
        }
        return m;
    }
};
