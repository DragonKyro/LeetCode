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
    int nonSpecialCount(int l, int r) {
        int limit = sqrt(r);
        vector<bool> sieve(limit+1, true);
        sieve[0] = sieve[1] = false;
        for (int i = 2; i*i <= limit; i++)
            if (sieve[i]) for (int j = i*i; j <= limit; j += i) sieve[j] = false;
        int special = 0;
        for (int p = 2; p <= limit; p++)
            if (sieve[p] && (long long)p*p >= l && (long long)p*p <= r) special++;
        return (r - l + 1) - special;
    }
};
