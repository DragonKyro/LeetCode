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
    unordered_map<int, vector<TreeNode*>> memo;
    vector<TreeNode*> allPossibleFBT(int n) {
        if (n % 2 == 0) return {};
        if (memo.count(n)) return memo[n];
        if (n == 1) return memo[n] = {new TreeNode(0)};
        vector<TreeNode*> result;
        for (int left = 1; left < n; left += 2) {
            int right = n - 1 - left;
            for (auto l : allPossibleFBT(left))
                for (auto r : allPossibleFBT(right))
                    result.push_back(new TreeNode(0, l, r));
        }
        return memo[n] = result;
    }
};
