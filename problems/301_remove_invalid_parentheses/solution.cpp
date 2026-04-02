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
    vector<string> res;
    vector<string> removeInvalidParentheses(string s) {
        int left = 0, right = 0;
        for (char c : s) {
            if (c == '(') left++;
            else if (c == ')') {
                if (left > 0) left--;
                else right++;
            }
        }
        dfs(s, 0, left, right);
        return res;
    }
    void dfs(string s, int start, int left, int right) {
        if (left == 0 && right == 0) {
            if (isValid(s)) res.push_back(s);
            return;
        }
        for (int i = start; i < s.size(); i++) {
            if (i > start && s[i] == s[i - 1]) continue;
            if (s[i] == ')' && right > 0)
                dfs(s.substr(0, i) + s.substr(i + 1), i, left, right - 1);
            else if (s[i] == '(' && left > 0)
                dfs(s.substr(0, i) + s.substr(i + 1), i, left - 1, right);
        }
    }
    bool isValid(string s) {
        int count = 0;
        for (char c : s) {
            if (c == '(') count++;
            else if (c == ')') count--;
            if (count < 0) return false;
        }
        return count == 0;
    }
};
