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
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> mat(n, vector<int>(n+1, 0));
        for (auto& q : queries)
            for (int r=q[0];r<=q[2];r++) { mat[r][q[1]]++; if (q[3]+1<n) mat[r][q[3]+1]--; }
        vector<vector<int>> res(n, vector<int>(n));
        for (int r=0;r<n;r++) { int s=0; for (int c=0;c<n;c++) { s+=mat[r][c]; res[r][c]=s; } }
        return res;
    }
};
