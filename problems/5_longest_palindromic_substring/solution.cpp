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
    string longestPalindrome(string s) {
        int start = 0, maxLen = 0;
        for (int i = 0; i < s.size(); i++) {
            for (int d = 0; d <= 1; d++) {
                int l = i, r = i + d;
                while (l >= 0 && r < s.size() && s[l] == s[r]) {
                    if (r - l + 1 > maxLen) {
                        start = l;
                        maxLen = r - l + 1;
                    }
                    l--;
                    r++;
                }
            }
        }
        return s.substr(start, maxLen);
    }
};
