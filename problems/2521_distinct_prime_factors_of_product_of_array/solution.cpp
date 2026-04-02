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
    int distinctPrimeFactors(vector<int>& nums) {
        set<int> primes;
        for (int n : nums) {
            for (int d=2; d*d<=n; d++) { if (n%d==0) { primes.insert(d); while(n%d==0) n/=d; } }
            if (n > 1) primes.insert(n);
        }
        return primes.size();
    }
};
