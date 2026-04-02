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
    int minimumLength(string s) {
        int cnt[26] = {};
        for (char c : s) cnt[c-'a']++;
        int res = 0;
        for (int v : cnt) if (v > 0) res += v % 2 == 0 ? 2 : 1;
        return res;
    }
};
