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
    int numWays(string s) {
        long long MOD = 1e9 + 7;
        int ones = count(s.begin(), s.end(), '1');
        if (ones % 3 != 0) return 0;
        int n = s.size();
        if (ones == 0) return (long long)(n - 1) * (n - 2) / 2 % MOD;
        int target = ones / 3;
        long long ways1 = 0, ways2 = 0;
        int cnt = 0;
        for (char c : s) {
            if (c == '1') cnt++;
            if (cnt == target) ways1++;
            if (cnt == 2 * target) ways2++;
        }
        return ways1 * ways2 % MOD;
    }
};
