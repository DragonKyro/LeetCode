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
    int maxPower(string s) {
        int res = 1, cur = 1;
        for (int i = 1; i < (int)s.size(); i++) {
            if (s[i] == s[i-1]) res = max(res, ++cur);
            else cur = 1;
        }
        return res;
    }
};
