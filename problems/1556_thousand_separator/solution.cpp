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
    string thousandSeparator(int n) {
        string s = to_string(n);
        string res;
        for (int i = 0; i < (int)s.size(); i++) {
            if (i > 0 && (s.size() - i) % 3 == 0) res += '.';
            res += s[i];
        }
        return res;
    }
};
