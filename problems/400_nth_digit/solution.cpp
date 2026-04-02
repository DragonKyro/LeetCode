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
    int findNthDigit(int n) {
        int digits = 1;
        long count = 9, start = 1;
        while (n > digits * count) {
            n -= digits * count;
            digits++;
            count *= 10;
            start *= 10;
        }
        long num = start + (n - 1) / digits;
        return to_string(num)[(n - 1) % digits] - '0';
    }
};
