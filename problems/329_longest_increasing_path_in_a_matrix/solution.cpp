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
    int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    vector<vector<int>> memo;
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        memo.assign(m, vector<int>(n, 0));
        int res = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                res = max(res, dfs(matrix, i, j, m, n));
        return res;
    }
    int dfs(vector<vector<int>>& mat, int i, int j, int m, int n) {
        if (memo[i][j]) return memo[i][j];
        int best = 1;
        for (auto& d : dirs) {
            int ni = i + d[0], nj = j + d[1];
            if (ni >= 0 && ni < m && nj >= 0 && nj < n && mat[ni][nj] > mat[i][j])
                best = max(best, 1 + dfs(mat, ni, nj, m, n));
        }
        return memo[i][j] = best;
    }
};
