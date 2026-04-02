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
    int scoreOfString(string s) {
        int res = 0;
        for (int i = 0; i < (int)s.size() - 1; i++)
            res += abs(s[i] - s[i + 1]);
        return res;
    }
};
