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
    int valueAfterKSeconds(int n, int k) {
        int MOD = 1e9+7;
        vector<long long> a(n, 1);
        for (int t = 0; t < k; t++)
            for (int i = 1; i < n; i++)
                a[i] = (a[i] + a[i-1]) % MOD;
        return a[n-1];
    }
};
