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
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        int res = INT_MIN;
        for (int left = 0; left < n; left++) {
            vector<int> rowSum(m, 0);
            for (int right = left; right < n; right++) {
                for (int i = 0; i < m; i++) rowSum[i] += matrix[i][right];
                set<int> s;
                s.insert(0);
                int prefix = 0;
                for (int val : rowSum) {
                    prefix += val;
                    auto it = s.lower_bound(prefix - k);
                    if (it != s.end()) res = max(res, prefix - *it);
                    s.insert(prefix);
                }
            }
        }
        return res;
    }
};
