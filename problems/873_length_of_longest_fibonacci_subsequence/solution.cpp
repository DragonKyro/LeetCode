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
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> index;
        for (int i = 0; i < n; i++) index[arr[i]] = i;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int result = 0;
        for (int k = 0; k < n; k++) for (int j = 0; j < k; j++) {
            int iVal = arr[k] - arr[j];
            if (iVal < arr[j] && index.count(iVal)) {
                int i = index[iVal];
                dp[j][k] = max(dp[i][j] + 1, 3);
                result = max(result, dp[j][k]);
            }
        }
        return result;
    }
};
