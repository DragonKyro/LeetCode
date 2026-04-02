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
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m=grid.size(),n=grid[0].size(),res=0;
        vector<vector<int>> px(m+1,vector<int>(n+1)),py(m+1,vector<int>(n+1));
        for (int i=0;i<m;i++)
            for (int j=0;j<n;j++) {
                px[i+1][j+1]=px[i][j+1]+px[i+1][j]-px[i][j]+(grid[i][j]=='X');
                py[i+1][j+1]=py[i][j+1]+py[i+1][j]-py[i][j]+(grid[i][j]=='Y');
                if (px[i+1][j+1]>0 && px[i+1][j+1]==py[i+1][j+1]) res++;
            }
        return res;
    }
};
