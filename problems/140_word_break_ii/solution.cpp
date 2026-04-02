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
    unordered_map<int, vector<string>> memo;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        return backtrack(s, wordSet, 0);
    }
    vector<string> backtrack(string& s, unordered_set<string>& wordSet, int start) {
        if (memo.count(start)) return memo[start];
        vector<string> result;
        if (start == s.size()) { result.push_back(""); return result; }
        for (int end = start + 1; end <= s.size(); end++) {
            string word = s.substr(start, end - start);
            if (wordSet.count(word)) {
                for (string& rest : backtrack(s, wordSet, end)) {
                    result.push_back(word + (rest.empty() ? "" : " " + rest));
                }
            }
        }
        memo[start] = result;
        return result;
    }
};
