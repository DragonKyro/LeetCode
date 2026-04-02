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
    int totalMoney(int n) {
        int weeks = n / 7, days = n % 7, total = 0;
        for (int w = 0; w < weeks; w++) total += 28 + 7 * w;
        for (int d = 0; d < days; d++) total += weeks + 1 + d;
        return total;
    }
};
