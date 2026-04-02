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
    int removePalindromeSub(string s) {
        if (s.empty()) return 0;
        string rev = s; reverse(rev.begin(), rev.end());
        return s == rev ? 1 : 2;
    }
};
