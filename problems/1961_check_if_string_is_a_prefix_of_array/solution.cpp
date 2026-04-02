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
    bool isPrefixString(string s, vector<string>& words) {
        string prefix;
        for (auto& w : words) {
            prefix += w;
            if (prefix == s) return true;
            if (prefix.size() > s.size()) return false;
        }
        return false;
    }
};
