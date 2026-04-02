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
    int findTheLongestBalancedSubstring(string s) {
        int ans = 0, zeros = 0, ones = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') { if (i > 0 && s[i-1] == '1') zeros = 0; zeros++; }
            else { ones++; ans = max(ans, 2*min(zeros, ones)); }
        }
        return ans;
    }
};
