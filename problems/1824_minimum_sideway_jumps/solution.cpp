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
    int minSideJumps(vector<int>& obstacles) {
        vector<int> dp = {1, 0, 1};
        for (int i = 1; i < obstacles.size(); i++) {
            for (int j = 0; j < 3; j++) {
                if (obstacles[i] == j + 1) dp[j] = 1000001;
            }
            for (int j = 0; j < 3; j++) {
                if (obstacles[i] != j + 1) {
                    for (int k = 0; k < 3; k++) {
                        if (k != j && obstacles[i] != k + 1) {
                            dp[j] = min(dp[j], dp[k] + 1);
                        }
                    }
                }
            }
        }
        return *min_element(dp.begin(), dp.end());
    }
};
