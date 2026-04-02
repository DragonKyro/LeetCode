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
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long total = 0;
        int minAbs = INT_MAX, negCount = 0;
        for (auto& row : matrix) {
            for (int x : row) {
                total += abs(x);
                minAbs = min(minAbs, abs(x));
                if (x < 0) negCount++;
            }
        }
        if (negCount % 2 == 1) total -= 2 * minAbs;
        return total;
    }
};
