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
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> wordSet(words.begin(), words.end());
        vector<string> result;
        for (auto& word : words) {
            if (word.empty()) continue;
            int n = word.size();
            vector<bool> dp(n + 1, false);
            dp[0] = true;
            for (int i = 1; i <= n; i++) {
                for (int j = 0; j < i; j++) {
                    string sub = word.substr(j, i - j);
                    if (dp[j] && sub != word && wordSet.count(sub)) {
                        dp[i] = true;
                        break;
                    }
                }
            }
            if (dp[n]) result.push_back(word);
        }
        return result;
    }
};
