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
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        int res = 10, unique = 9, avail = 9;
        for (int i = 2; i <= min(n, 10); i++) {
            unique *= avail;
            res += unique;
            avail--;
        }
        return res;
    }
};
