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
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for (int r = 0; r < 4; r++) {
            if (mat == target) return true;
            mat = rotate(mat);
        }
        return false;
    }
    vector<vector<int>> rotate(vector<vector<int>>& m) {
        int n = m.size();
        vector<vector<int>> res(n, vector<int>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                res[i][j] = m[n - 1 - j][i];
        return res;
    }
};
