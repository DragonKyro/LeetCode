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
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(query_row + 1);
        for (int i = 0; i <= query_row; i++) dp[i].resize(i + 1, 0.0);
        dp[0][0] = poured;
        for (int i = 0; i < query_row; i++) {
            for (int j = 0; j < (int)dp[i].size(); j++) {
                double overflow = (dp[i][j] - 1.0) / 2.0;
                if (overflow > 0) {
                    dp[i+1][j] += overflow;
                    dp[i+1][j+1] += overflow;
                }
            }
        }
        return min(1.0, dp[query_row][query_glass]);
    }
};
