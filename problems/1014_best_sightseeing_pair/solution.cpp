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
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans = 0, best = values[0];
        for (int j = 1; j < values.size(); j++) {
            ans = max(ans, best + values[j] - j);
            best = max(best, values[j] + j);
        }
        return ans;
    }
};
