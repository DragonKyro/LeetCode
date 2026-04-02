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
    bool backspaceCompare(string s, string t) {
        return build(s) == build(t);
    }
    string build(string& s) {
        string res;
        for (char c : s) {
            if (c == '#') { if (!res.empty()) res.pop_back(); }
            else res += c;
        }
        return res;
    }
};
