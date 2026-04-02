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
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        int sign = (dividend > 0) ^ (divisor > 0) ? -1 : 1;
        long a = labs(dividend), b = labs(divisor);
        int res = 0;
        while (a >= b) {
            long temp = b;
            int m = 1;
            while (a >= (temp << 1)) { temp <<= 1; m <<= 1; }
            a -= temp;
            res += m;
        }
        return sign * res;
    }
};
