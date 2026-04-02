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
    long long getDescentPeriods(vector<int>& prices) {
        long long result = 0, count = 1;
        for (int i = 0; i < (int)prices.size(); i++) {
            if (i > 0 && prices[i] == prices[i - 1] - 1) count++;
            else count = 1;
            result += count;
        }
        return result;
    }
};
