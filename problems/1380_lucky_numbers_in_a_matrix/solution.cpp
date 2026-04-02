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
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        set<int> minRows;
        for (auto& row : matrix) minRows.insert(*min_element(row.begin(), row.end()));
        vector<int> res;
        for (int j = 0; j < n; j++) {
            int mx = matrix[0][j];
            for (int i = 1; i < m; i++) mx = max(mx, matrix[i][j]);
            if (minRows.count(mx)) res.push_back(mx);
        }
        return res;
    }
};
