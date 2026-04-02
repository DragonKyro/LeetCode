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
    int MOD = 1337;
    int superPow(int a, vector<int>& b) {
        int result = 1;
        for (int digit : b)
            result = powmod(result, 10) * powmod(a, digit) % MOD;
        return result;
    }
    int powmod(int base, int exp) {
        base %= MOD;
        int result = 1;
        while (exp > 0) {
            if (exp & 1) result = (long)result * base % MOD;
            base = (long)base * base % MOD;
            exp >>= 1;
        }
        return result;
    }
};
