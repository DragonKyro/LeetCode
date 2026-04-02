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
    bool judgeSquareSum(int c) {
        long a = 0;
        while (a * a <= c) {
            long b2 = (long)c - a * a;
            long b = (long)sqrt(b2);
            if (b * b == b2) return true;
            a++;
        }
        return false;
    }
};
