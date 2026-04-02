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
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        unordered_map<int, vector<int>> d;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) d[i-j].push_back(mat[i][j]);
        for (auto& [k, v] : d) sort(v.rbegin(), v.rend());
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) { mat[i][j] = d[i-j].back(); d[i-j].pop_back(); }
        return mat;
    }
};
