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
    int countGoodNumbers(long long n) {
        long long MOD = 1e9 + 7;
        long long even = (n + 1) / 2, odd = n / 2;
        return power(5, even, MOD) * power(4, odd, MOD) % MOD;
    }
    long long power(long long base, long long exp, long long mod) {
        long long result = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1) result = result * base % mod;
            exp /= 2;
            base = base * base % mod;
        }
        return result;
    }
};
