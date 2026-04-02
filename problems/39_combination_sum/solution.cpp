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
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> path;
        function<void(int, int)> bt = [&](int start, int remain) {
            if (remain == 0) { res.push_back(path); return; }
            for (int i = start; i < candidates.size(); i++) {
                if (candidates[i] > remain) continue;
                path.push_back(candidates[i]);
                bt(i, remain - candidates[i]);
                path.pop_back();
            }
        };
        bt(0, target);
        return res;
    }
};
