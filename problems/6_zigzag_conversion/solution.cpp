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
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.size()) return s;
        vector<string> rows(numRows);
        int idx = 0, step = 1;
        for (char c : s) {
            rows[idx] += c;
            if (idx == 0) step = 1;
            else if (idx == numRows - 1) step = -1;
            idx += step;
        }
        string res;
        for (auto& row : rows) res += row;
        return res;
    }
};
