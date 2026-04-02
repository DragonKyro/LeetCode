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
    int countBinarySubstrings(string s) {
        int prev = 0, cur = 1, result = 0;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i-1]) cur++;
            else { result += min(prev, cur); prev = cur; cur = 1; }
        }
        return result + min(prev, cur);
    }
};
