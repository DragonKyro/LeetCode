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
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (s.empty() || words.empty()) return res;
        int wordLen = words[0].size(), numWords = words.size();
        unordered_map<string, int> wordCount;
        for (auto& w : words) wordCount[w]++;
        for (int i = 0; i < wordLen; i++) {
            int left = i, matched = 0;
            unordered_map<string, int> count;
            for (int j = i; j <= (int)s.size() - wordLen; j += wordLen) {
                string word = s.substr(j, wordLen);
                if (wordCount.count(word)) {
                    count[word]++;
                    matched++;
                    while (count[word] > wordCount[word]) {
                        string lw = s.substr(left, wordLen);
                        count[lw]--;
                        matched--;
                        left += wordLen;
                    }
                    if (matched == numWords) res.push_back(left);
                } else {
                    count.clear();
                    matched = 0;
                    left = j + wordLen;
                }
            }
        }
        return res;
    }
};
