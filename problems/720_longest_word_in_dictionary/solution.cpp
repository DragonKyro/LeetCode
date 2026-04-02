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
    string longestWord(vector<string>& words) {
        unordered_set<string> st(words.begin(), words.end());
        string ans;
        for (auto& word : words) {
            if (word.size() > ans.size() || (word.size() == ans.size() && word < ans)) {
                bool valid = true;
                for (int k = 1; k < (int)word.size(); k++) {
                    if (!st.count(word.substr(0, k))) { valid = false; break; }
                }
                if (valid) ans = word;
            }
        }
        return ans;
    }
};
