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
    int countVowelPermutation(int n) {
        long long MOD = 1e9 + 7;
        long long a = 1, e = 1, i = 1, o = 1, u = 1;
        for (int k = 1; k < n; k++) {
            long long na = e, ne = (a+i)%MOD, ni = (a+e+o+u)%MOD, no = (i+u)%MOD, nu = a;
            a = na; e = ne; i = ni; o = no; u = nu;
        }
        return (a+e+i+o+u) % MOD;
    }
};
