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
    bool isNumber(string s) {
        int i = 0, n = s.size();
        while (i < n && s[i] == ' ') i++;
        while (n > 0 && s[n - 1] == ' ') n--;
        if (i >= n) return false;
        bool numSeen = false, dotSeen = false, eSeen = false;
        for (; i < n; i++) {
            char c = s[i];
            if (c >= '0' && c <= '9') numSeen = true;
            else if (c == '.') {
                if (dotSeen || eSeen) return false;
                dotSeen = true;
            } else if (c == 'e' || c == 'E') {
                if (eSeen || !numSeen) return false;
                eSeen = true;
                numSeen = false;
            } else if (c == '+' || c == '-') {
                if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E') return false;
            } else return false;
        }
        return numSeen;
    }
};
