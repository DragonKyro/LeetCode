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
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> result;
        int r = 0, c = 0;
        bool goingUp = true;
        while (result.size() < m * n) {
            result.push_back(mat[r][c]);
            if (goingUp) {
                if (c == n - 1) { r++; goingUp = false; }
                else if (r == 0) { c++; goingUp = false; }
                else { r--; c++; }
            } else {
                if (r == m - 1) { c++; goingUp = true; }
                else if (c == 0) { r++; goingUp = true; }
                else { r++; c--; }
            }
        }
        return result;
    }
};
