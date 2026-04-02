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
    int calculate(string s) {
        stack<int> stk;
        int num = 0;
        char op = '+';
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (isdigit(c)) num = num * 10 + (c - '0');
            if ((!isdigit(c) && c != ' ') || i == s.size() - 1) {
                if (op == '+') stk.push(num);
                else if (op == '-') stk.push(-num);
                else if (op == '*') { int top = stk.top(); stk.pop(); stk.push(top * num); }
                else if (op == '/') { int top = stk.top(); stk.pop(); stk.push(top / num); }
                op = c;
                num = 0;
            }
        }
        int result = 0;
        while (!stk.empty()) { result += stk.top(); stk.pop(); }
        return result;
    }
};
