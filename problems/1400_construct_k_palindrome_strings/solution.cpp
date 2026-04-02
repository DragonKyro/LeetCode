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
    bool canConstruct(string s, int k) {
        if (k > (int)s.size()) return false;
        int cnt[26] = {};
        for (char c : s) cnt[c-'a']++;
        int odd = 0;
        for (int c : cnt) if (c % 2 == 1) odd++;
        return odd <= k;
    }
};
