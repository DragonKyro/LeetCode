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
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int best = matrix[i - 1][j];
                if (j > 0) best = min(best, matrix[i - 1][j - 1]);
                if (j < n - 1) best = min(best, matrix[i - 1][j + 1]);
                matrix[i][j] += best;
            }
        }
        return *min_element(matrix[n - 1].begin(), matrix[n - 1].end());
    }
};
