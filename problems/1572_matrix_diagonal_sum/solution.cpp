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
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size(), total = 0;
        for (int i = 0; i < n; i++) total += mat[i][i] + mat[i][n - 1 - i];
        if (n % 2 == 1) total -= mat[n / 2][n / 2];
        return total;
    }
};
