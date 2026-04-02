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
    int monkeyMove(int n) {
        long long MOD = 1e9+7;
        auto pw = [&](long long b, int e) { long long r=1; b%=MOD; while(e>0){if(e&1)r=r*b%MOD;b=b*b%MOD;e>>=1;} return r; };
        return (pw(2, n) - 2 + MOD) % MOD;
    }
};
