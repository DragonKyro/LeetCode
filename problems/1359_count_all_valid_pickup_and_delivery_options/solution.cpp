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
    int countOrders(int n) {
        long long MOD = 1e9 + 7, res = 1;
        for (int i = 1; i <= n; i++) {
            res = res * i % MOD;
            res = res * (2 * i - 1) % MOD;
        }
        return res;
    }
};
