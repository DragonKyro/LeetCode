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
    int countPrimeSetBits(int left, int right) {
        unordered_set<int> primes = {2,3,5,7,11,13,17,19};
        int count = 0;
        for (int n = left; n <= right; n++)
            if (primes.count(__builtin_popcount(n))) count++;
        return count;
    }
};
