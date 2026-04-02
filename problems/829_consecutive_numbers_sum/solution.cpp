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
    int consecutiveNumbersSum(int n) {
        int count = 0;
        for (int k = 1; (long)k * (k - 1) / 2 < n; k++) {
            if ((n - k * (k - 1) / 2) % k == 0) count++;
        }
        return count;
    }
};
