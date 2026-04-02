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
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int lo = 0, hi = m - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            int maxCol = max_element(mat[mid].begin(), mat[mid].end()) - mat[mid].begin();
            int above = mid > 0 ? mat[mid - 1][maxCol] : -1;
            int below = mid < m - 1 ? mat[mid + 1][maxCol] : -1;
            if (mat[mid][maxCol] > above && mat[mid][maxCol] > below) return {mid, maxCol};
            else if (above > mat[mid][maxCol]) hi = mid - 1;
            else lo = mid + 1;
        }
        return {-1, -1};
    }
};
