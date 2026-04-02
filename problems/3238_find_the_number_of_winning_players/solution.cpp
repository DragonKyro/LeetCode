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
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        vector<vector<int>> cnt(n, vector<int>(11, 0));
        for (auto& p : pick) cnt[p[0]][p[1]]++;
        int res = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j <= 10; j++)
                if (cnt[i][j] > i) { res++; break; }
        return res;
    }
};
