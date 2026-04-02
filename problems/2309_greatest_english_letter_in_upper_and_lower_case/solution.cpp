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
    string greatestLetter(string s) {
        set<char> chars(s.begin(), s.end());
        for (char c = 'Z'; c >= 'A'; c--) {
            if (chars.count(c) && chars.count(tolower(c))) return string(1, c);
        }
        return "";
    }
};
