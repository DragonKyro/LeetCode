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
    int findLUSlength(vector<string>& strs) {
        auto isSubseq = [](const string& s, const string& t) {
            int i = 0;
            for (int j = 0; j < (int)t.size() && i < (int)s.size(); j++)
                if (s[i] == t[j]) i++;
            return i == (int)s.size();
        };
        sort(strs.begin(), strs.end(), [](auto& a, auto& b) { return a.size() > b.size(); });
        for (int i = 0; i < (int)strs.size(); i++) {
            bool unique = true;
            for (int j = 0; j < (int)strs.size(); j++) {
                if (i != j && isSubseq(strs[i], strs[j])) { unique = false; break; }
            }
            if (unique) return strs[i].size();
        }
        return -1;
    }
};
