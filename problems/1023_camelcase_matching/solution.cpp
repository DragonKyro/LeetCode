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
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> res;
        for (auto& q : queries) {
            int j = 0;
            bool ok = true;
            for (char c : q) {
                if (j < pattern.size() && c == pattern[j]) j++;
                else if (isupper(c)) { ok = false; break; }
            }
            res.push_back(ok && j == pattern.size());
        }
        return res;
    }
};
