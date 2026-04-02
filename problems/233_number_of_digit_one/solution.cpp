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
    int countDigitOne(int n) {
        int count = 0;
        for (long factor = 1; factor <= n; factor *= 10) {
            long lower = n % factor;
            long curr = (n / factor) % 10;
            long higher = n / (factor * 10);
            if (curr == 0) count += higher * factor;
            else if (curr == 1) count += higher * factor + lower + 1;
            else count += (higher + 1) * factor;
        }
        return count;
    }
};
