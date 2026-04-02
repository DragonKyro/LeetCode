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
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int count = 0;
        for (int r = 0; r + 2 < grid.size(); r++)
            for (int c = 0; c + 2 < grid[0].size(); c++)
                if (isMagic(grid, r, c)) count++;
        return count;
    }
    bool isMagic(vector<vector<int>>& g, int r, int c) {
        bool seen[10] = {};
        for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) {
            int v = g[r+i][c+j];
            if (v < 1 || v > 9 || seen[v]) return false;
            seen[v] = true;
        }
        for (int i = 0; i < 3; i++) {
            if (g[r+i][c]+g[r+i][c+1]+g[r+i][c+2] != 15) return false;
            if (g[r][c+i]+g[r+1][c+i]+g[r+2][c+i] != 15) return false;
        }
        if (g[r][c]+g[r+1][c+1]+g[r+2][c+2] != 15) return false;
        if (g[r][c+2]+g[r+1][c+1]+g[r+2][c] != 15) return false;
        return true;
    }
};
