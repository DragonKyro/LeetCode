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
    bool buddyStrings(string s, string goal) {
        if (s.size() != goal.size()) return false;
        if (s == goal) {
            set<char> st(s.begin(), s.end());
            return st.size() < s.size();
        }
        vector<int> diffs;
        for (int i = 0; i < s.size(); i++) if (s[i] != goal[i]) diffs.push_back(i);
        return diffs.size() == 2 && s[diffs[0]] == goal[diffs[1]] && s[diffs[1]] == goal[diffs[0]];
    }
};
