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
    string modifyString(string s) {
        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == '?') {
                for (char c = 'a'; c <= 'c'; c++) {
                    if ((i == 0 || s[i-1] != c) && (i == (int)s.size() - 1 || s[i+1] != c)) {
                        s[i] = c;
                        break;
                    }
                }
            }
        }
        return s;
    }
};
