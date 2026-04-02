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
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> path;
        backtrack(res, path, k, n, 1);
        return res;
    }

    void backtrack(vector<vector<int>>& res, vector<int>& path, int k, int remain, int start) {
        if (path.size() == k) {
            if (remain == 0) res.push_back(path);
            return;
        }
        for (int i = start; i <= 9; i++) {
            if (i > remain) break;
            path.push_back(i);
            backtrack(res, path, k, remain - i, i + 1);
            path.pop_back();
        }
    }
};
