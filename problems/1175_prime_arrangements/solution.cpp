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
    int numPrimeArrangements(int n) {
        int MOD = 1e9 + 7;
        int primes = countPrimes(n);
        long long result = 1;
        for (int i = 2; i <= primes; i++) result = result * i % MOD;
        for (int i = 2; i <= n - primes; i++) result = result * i % MOD;
        return result;
    }
    int countPrimes(int n) {
        if (n < 2) return 0;
        vector<bool> sieve(n + 1, true);
        sieve[0] = sieve[1] = false;
        for (int i = 2; i * i <= n; i++)
            if (sieve[i])
                for (int j = i * i; j <= n; j += i) sieve[j] = false;
        return count(sieve.begin(), sieve.end(), true);
    }
};
