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
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size(), n = land[0].size();
        vector<vector<int>> result;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (land[i][j] == 1) {
                    int r2 = i, c2 = j;
                    while (r2 + 1 < m && land[r2 + 1][j] == 1) r2++;
                    while (c2 + 1 < n && land[i][c2 + 1] == 1) c2++;
                    result.push_back({i, j, r2, c2});
                    for (int r = i; r <= r2; r++)
                        for (int c = j; c <= c2; c++) land[r][c] = 0;
                }
            }
        }
        return result;
    }
};
