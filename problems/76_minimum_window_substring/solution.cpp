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
    string minWindow(string s, string t) {
        int need[128] = {};
        for (char c : t) need[c]++;
        int missing = t.size(), left = 0, start = 0, minLen = INT_MAX;
        for (int right = 0; right < (int)s.size(); right++) {
            if (need[s[right]]-- > 0) missing--;
            while (missing == 0) {
                if (right - left + 1 < minLen) { minLen = right - left + 1; start = left; }
                if (++need[s[left++]] > 0) missing++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
