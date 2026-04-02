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

class NeighborSum {
    vector<vector<int>> grid;
    unordered_map<int, pair<int,int>> pos;
    int n;
public:
    NeighborSum(vector<vector<int>>& grid) : grid(grid), n(grid.size()) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                pos[grid[i][j]] = {i, j};
    }
    int adjacentSum(int value) {
        auto [i,j] = pos[value];
        int s = 0;
        for (auto [di,dj] : vector<pair<int,int>>{{-1,0},{1,0},{0,-1},{0,1}}) {
            int ni=i+di, nj=j+dj;
            if (ni>=0&&ni<n&&nj>=0&&nj<n) s += grid[ni][nj];
        }
        return s;
    }
    int diagonalSum(int value) {
        auto [i,j] = pos[value];
        int s = 0;
        for (auto [di,dj] : vector<pair<int,int>>{{-1,-1},{-1,1},{1,-1},{1,1}}) {
            int ni=i+di, nj=j+dj;
            if (ni>=0&&ni<n&&nj>=0&&nj<n) s += grid[ni][nj];
        }
        return s;
    }
};
