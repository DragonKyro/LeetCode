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
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> result = {{rStart, cStart}};
        int dr[] = {0,1,0,-1}, dc[] = {1,0,-1,0};
        int d = 0, steps = 1, r = rStart, c = cStart;
        while (result.size() < rows * cols) {
            for (int t = 0; t < 2; t++) {
                for (int s = 0; s < steps; s++) {
                    r += dr[d]; c += dc[d];
                    if (r >= 0 && r < rows && c >= 0 && c < cols) result.push_back({r, c});
                }
                d = (d + 1) % 4;
            }
            steps++;
        }
        return result;
    }
};
