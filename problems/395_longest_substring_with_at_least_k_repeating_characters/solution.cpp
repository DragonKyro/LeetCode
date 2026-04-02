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
    int longestSubstring(string s, int k) {
        if ((int)s.size() < k) return 0;
        int count[26] = {};
        for (char c : s) count[c - 'a']++;
        for (int i = 0; i < 26; i++) {
            if (count[i] > 0 && count[i] < k) {
                char c = 'a' + i;
                int res = 0;
                stringstream ss(s);
                string sub;
                while (getline(ss, sub, c))
                    res = max(res, longestSubstring(sub, k));
                return res;
            }
        }
        return s.size();
    }
};
