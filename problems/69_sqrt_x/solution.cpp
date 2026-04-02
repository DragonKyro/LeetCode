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
    int mySqrt(int x) {
        if (x < 2) return x;
        long left = 1, right = x / 2;
        while (left <= right) {
            long mid = left + (right - left) / 2;
            if (mid * mid == x) return mid;
            else if (mid * mid < x) left = mid + 1;
            else right = mid - 1;
        }
        return right;
    }
};
