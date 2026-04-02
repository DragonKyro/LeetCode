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
    string reverseParentheses(string s) {
        stack<string> stk;
        stk.push("");
        for (char ch : s) {
            if (ch == '(') {
                stk.push("");
            } else if (ch == ')') {
                string top = stk.top();
                stk.pop();
                reverse(top.begin(), top.end());
                stk.top() += top;
            } else {
                stk.top() += ch;
            }
        }
        return stk.top();
    }
};
