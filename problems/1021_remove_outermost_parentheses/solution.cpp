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
    string removeOuterParentheses(string s) {
        string result;
        int depth = 0;
        for (char c : s) {
            if (c == '(') { if (depth > 0) result += c; depth++; }
            else { depth--; if (depth > 0) result += c; }
        }
        return result;
    }
};
