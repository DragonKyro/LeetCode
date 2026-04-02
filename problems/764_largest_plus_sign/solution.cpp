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
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> grid(n, vector<int>(n, 1));
        for (auto& m : mines) grid[m[0]][m[1]] = 0;
        vector<vector<int>> L(n, vector<int>(n)), R(n, vector<int>(n)), U(n, vector<int>(n)), D(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) L[i][j] = !grid[i][j] ? 0 : (j > 0 ? L[i][j-1]+1 : 1);
            for (int j = n-1; j >= 0; j--) R[i][j] = !grid[i][j] ? 0 : (j < n-1 ? R[i][j+1]+1 : 1);
        }
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < n; i++) U[i][j] = !grid[i][j] ? 0 : (i > 0 ? U[i-1][j]+1 : 1);
            for (int i = n-1; i >= 0; i--) D[i][j] = !grid[i][j] ? 0 : (i < n-1 ? D[i+1][j]+1 : 1);
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                ans = max(ans, min({L[i][j], R[i][j], U[i][j], D[i][j]}));
        return ans;
    }
};
