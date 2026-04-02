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
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        vector<vector<int>> cells;
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                cells.push_back({i, j});
        sort(cells.begin(), cells.end(), [&](auto& a, auto& b) {
            return abs(a[0]-rCenter)+abs(a[1]-cCenter) < abs(b[0]-rCenter)+abs(b[1]-cCenter);
        });
        return cells;
    }
};
