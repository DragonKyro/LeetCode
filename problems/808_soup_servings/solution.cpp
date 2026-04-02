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
    unordered_map<int, double> memo;
    double soupServings(int n) {
        if (n > 4800) return 1.0;
        n = (n + 24) / 25;
        return dp(n, n);
    }
    double dp(int a, int b) {
        if (a <= 0 && b <= 0) return 0.5;
        if (a <= 0) return 1.0;
        if (b <= 0) return 0.0;
        int key = a * 200 + b;
        if (memo.count(key)) return memo[key];
        return memo[key] = 0.25 * (dp(a-4,b) + dp(a-3,b-1) + dp(a-2,b-2) + dp(a-1,b-3));
    }
};
