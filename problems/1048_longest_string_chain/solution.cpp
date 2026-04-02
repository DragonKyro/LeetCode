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
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](auto& a, auto& b) { return a.size() < b.size(); });
        unordered_map<string, int> dp;
        int ans = 1;
        for (auto& word : words) {
            dp[word] = 1;
            for (int i = 0; i < word.size(); i++) {
                string prev = word.substr(0, i) + word.substr(i + 1);
                if (dp.count(prev))
                    dp[word] = max(dp[word], dp[prev] + 1);
            }
            ans = max(ans, dp[word]);
        }
        return ans;
    }
};
