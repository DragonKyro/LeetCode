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
    int minExtraChar(string s, vector<string>& dictionary) {
        set<string> words(dictionary.begin(), dictionary.end());
        int n = s.size();
        vector<int> dp(n+1, 0);
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i-1]+1;
            for (int j = 0; j < i; j++)
                if (words.count(s.substr(j, i-j))) dp[i] = min(dp[i], dp[j]);
        }
        return dp[n];
    }
};
