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
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size(), result = 0;
        vector<pair<int,int>> dirs = {{1,1},{1,-1},{-1,1},{-1,-1}};
        for (auto [p, q] : dirs) {
            int minVal = INT_MAX, maxVal = INT_MIN;
            for (int i = 0; i < n; i++) {
                int val = p * arr1[i] + q * arr2[i] + i;
                minVal = min(minVal, val);
                maxVal = max(maxVal, val);
            }
            result = max(result, maxVal - minVal);
        }
        return result;
    }
};
