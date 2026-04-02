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
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size(), n = grid1[0].size(), count = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid2[i][j] == 1 && dfs(grid1, grid2, i, j)) count++;
        return count;
    }
    bool dfs(vector<vector<int>>& g1, vector<vector<int>>& g2, int i, int j) {
        if (i < 0 || i >= g1.size() || j < 0 || j >= g1[0].size() || g2[i][j] == 0) return true;
        g2[i][j] = 0;
        bool res = g1[i][j] == 1;
        res = dfs(g1, g2, i + 1, j) && res;
        res = dfs(g1, g2, i - 1, j) && res;
        res = dfs(g1, g2, i, j + 1) && res;
        res = dfs(g1, g2, i, j - 1) && res;
        return res;
    }
};
