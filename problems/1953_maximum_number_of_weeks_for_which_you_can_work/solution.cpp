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
    long long numberOfWeeks(vector<int>& milestones) {
        long long total = 0, maxVal = 0;
        for (int m : milestones) { total += m; maxVal = max(maxVal, (long long)m); }
        long long rest = total - maxVal;
        return maxVal > rest + 1 ? 2 * rest + 1 : total;
    }
};
