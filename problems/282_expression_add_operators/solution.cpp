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
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        backtrack(res, num, target, 0, "", 0, 0);
        return res;
    }

    void backtrack(vector<string>& res, string& num, int target, int idx, string path, long value, long prev) {
        if (idx == num.size()) {
            if (value == target) res.push_back(path);
            return;
        }
        for (int i = idx; i < num.size(); i++) {
            if (i > idx && num[idx] == '0') break;
            string s = num.substr(idx, i - idx + 1);
            long curr = stol(s);
            if (idx == 0) {
                backtrack(res, num, target, i + 1, s, curr, curr);
            } else {
                backtrack(res, num, target, i + 1, path + "+" + s, value + curr, curr);
                backtrack(res, num, target, i + 1, path + "-" + s, value - curr, -curr);
                backtrack(res, num, target, i + 1, path + "*" + s, value - prev + prev * curr, prev * curr);
            }
        }
    }
};
