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
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> combo;
        backtrack(1, n, k, combo, result);
        return result;
    }

    void backtrack(int start, int n, int k, vector<int>& combo, vector<vector<int>>& result) {
        if ((int)combo.size() == k) { result.push_back(combo); return; }
        for (int i = start; i <= n; i++) {
            combo.push_back(i);
            backtrack(i + 1, n, k, combo, result);
            combo.pop_back();
        }
    }
};
