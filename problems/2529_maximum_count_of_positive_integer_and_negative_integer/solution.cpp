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
    int countVowelStrings(int n) {
        int dp[5] = {1,1,1,1,1};
        for (int i = 1; i < n; i++)
            for (int j = 1; j < 5; j++) dp[j] += dp[j-1];
        return dp[0]+dp[1]+dp[2]+dp[3]+dp[4];
    }
};
