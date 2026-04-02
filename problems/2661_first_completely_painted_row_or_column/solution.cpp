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
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> row(m*n+1), col(m*n+1);
        for (int r=0;r<m;r++) for (int c=0;c<n;c++) { row[mat[r][c]]=r; col[mat[r][c]]=c; }
        vector<int> rc(m,0), cc(n,0);
        for (int i=0;i<arr.size();i++) {
            int r=row[arr[i]], c=col[arr[i]];
            rc[r]++; cc[c]++;
            if (rc[r]==n||cc[c]==m) return i;
        }
        return -1;
    }
};
