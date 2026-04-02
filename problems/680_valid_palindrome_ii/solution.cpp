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
    bool validPalindrome(string s) {
        int lo = 0, hi = s.size() - 1;
        while (lo < hi) {
            if (s[lo] != s[hi]) {
                return isPalin(s, lo + 1, hi) || isPalin(s, lo, hi - 1);
            }
            lo++; hi--;
        }
        return true;
    }
    bool isPalin(string& s, int lo, int hi) {
        while (lo < hi) {
            if (s[lo++] != s[hi--]) return false;
        }
        return true;
    }
};
