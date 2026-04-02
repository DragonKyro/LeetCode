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
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string path;
        function<void(int,int)> bt = [&](int open, int close) {
            if (path.size() == 2 * n) { res.push_back(path); return; }
            if (open < n) { path += '('; bt(open + 1, close); path.pop_back(); }
            if (close < open) { path += ')'; bt(open, close + 1); path.pop_back(); }
        };
        bt(0, 0);
        return res;
    }
};
