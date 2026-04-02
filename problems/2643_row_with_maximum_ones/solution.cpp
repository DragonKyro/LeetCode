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
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int bestR = 0, bestC = 0;
        for (int i = 0; i < mat.size(); i++) {
            int cnt = accumulate(mat[i].begin(), mat[i].end(), 0);
            if (cnt > bestC) { bestR = i; bestC = cnt; }
        }
        return {bestR, bestC};
    }
};
