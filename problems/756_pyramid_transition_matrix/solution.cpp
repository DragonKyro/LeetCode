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
    unordered_map<string, vector<char>> mapping;

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for (auto& s : allowed) mapping[s.substr(0,2)].push_back(s[2]);
        return solve(bottom, "", 0);
    }

    bool solve(string bottom, string next, int idx) {
        if (bottom.size() == 1) return true;
        if (idx == (int)bottom.size() - 1) return solve(next, "", 0);
        string key = bottom.substr(idx, 2);
        for (char c : mapping[key]) {
            if (solve(bottom, next + c, idx + 1)) return true;
        }
        return false;
    }
};
