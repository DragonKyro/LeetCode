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
    string reverseStr(string s, int k) {
        for (int i = 0; i < (int)s.size(); i += 2 * k) {
            reverse(s.begin() + i, s.begin() + min(i + k, (int)s.size()));
        }
        return s;
    }
};
