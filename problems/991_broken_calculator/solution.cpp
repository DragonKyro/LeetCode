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
    int brokenCalc(int startValue, int target) {
        int ops = 0;
        while (target > startValue) {
            if (target % 2 == 1) target++;
            else target /= 2;
            ops++;
        }
        return ops + startValue - target;
    }
};
