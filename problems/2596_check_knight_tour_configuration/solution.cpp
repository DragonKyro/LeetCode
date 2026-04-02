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
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<pair<int,int>> pos(n*n);
        for (int r=0;r<n;r++) for (int c=0;c<n;c++) pos[grid[r][c]]={r,c};
        if (pos[0]!=make_pair(0,0)) return false;
        for (int i=1;i<n*n;i++) {
            int dr=abs(pos[i].first-pos[i-1].first), dc=abs(pos[i].second-pos[i-1].second);
            if (!((dr==1&&dc==2)||(dr==2&&dc==1))) return false;
        }
        return true;
    }
};
