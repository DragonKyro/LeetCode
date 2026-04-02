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
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> res;
        for (auto& w : words) {
            string cur;
            for (char c : w) {
                if (c == separator) { if (!cur.empty()) res.push_back(cur); cur.clear(); }
                else cur += c;
            }
            if (!cur.empty()) res.push_back(cur);
        }
        return res;
    }
};
