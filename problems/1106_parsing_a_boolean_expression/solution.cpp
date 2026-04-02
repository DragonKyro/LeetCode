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
    bool parseBoolExpr(string expression) {
        stack<char> stk;
        for (char ch : expression) {
            if (ch == ',') continue;
            if (ch == ')') {
                vector<char> seen;
                while (stk.top() != '(') {
                    seen.push_back(stk.top());
                    stk.pop();
                }
                stk.pop();
                char op = stk.top();
                stk.pop();
                char result;
                if (op == '!') {
                    result = seen[0] == 't' ? 'f' : 't';
                } else if (op == '&') {
                    result = find(seen.begin(), seen.end(), 'f') != seen.end() ? 'f' : 't';
                } else {
                    result = find(seen.begin(), seen.end(), 't') != seen.end() ? 't' : 'f';
                }
                stk.push(result);
            } else {
                stk.push(ch);
            }
        }
        return stk.top() == 't';
    }
};
