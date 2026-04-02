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
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> result;
        for (auto& w : words) if (match(w, pattern)) result.push_back(w);
        return result;
    }
    bool match(string& w, string& p) {
        unordered_map<char, char> m1, m2;
        for (int i = 0; i < w.size(); i++) {
            if (m1.count(w[i]) && m1[w[i]] != p[i]) return false;
            if (m2.count(p[i]) && m2[p[i]] != w[i]) return false;
            m1[w[i]] = p[i]; m2[p[i]] = w[i];
        }
        return true;
    }
};
