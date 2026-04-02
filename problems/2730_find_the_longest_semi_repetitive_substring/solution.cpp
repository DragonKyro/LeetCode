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
    int longestSemiRepetitiveSubstring(string s) {
        int ans = 1, j = 0, pairs = 0;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i-1]) pairs++;
            while (pairs > 1) { j++; if (s[j]==s[j-1]) pairs--; }
            ans = max(ans, i-j+1);
        }
        return ans;
    }
};
