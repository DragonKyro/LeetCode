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
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int,int>> pts1, pts2;
        for (int r = 0; r < n; r++) for (int c = 0; c < n; c++) {
            if (img1[r][c]) pts1.push_back({r, c});
            if (img2[r][c]) pts2.push_back({r, c});
        }
        unordered_map<int, int> count;
        int result = 0;
        for (auto& [r1,c1] : pts1) for (auto& [r2,c2] : pts2) {
            int key = (r1-r2+30) * 100 + (c1-c2+30);
            result = max(result, ++count[key]);
        }
        return result;
    }
};
