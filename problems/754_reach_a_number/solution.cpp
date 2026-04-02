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
    int reachNumber(int target) {
        target = abs(target);
        int step = 0, total = 0;
        while (total < target || (total - target) % 2 != 0) {
            step++;
            total += step;
        }
        return step;
    }
};
