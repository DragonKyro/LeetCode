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
    int memo[100][100][100] = {};
    int removeBoxes(vector<int>& boxes) {
        return dp(boxes, 0, boxes.size() - 1, 0);
    }
    int dp(vector<int>& boxes, int l, int r, int k) {
        if (l > r) return 0;
        if (memo[l][r][k]) return memo[l][r][k];
        int origR = r, origK = k;
        while (r > l && boxes[r] == boxes[r-1]) { r--; k++; }
        int res = (k+1)*(k+1) + dp(boxes, l, r-1, 0);
        for (int i = l; i < r; i++)
            if (boxes[i] == boxes[r])
                res = max(res, dp(boxes, l, i, k+1) + dp(boxes, i+1, r-1, 0));
        return memo[l][origR][origK] = res;
    }
};
