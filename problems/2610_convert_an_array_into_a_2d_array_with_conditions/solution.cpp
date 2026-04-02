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
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int> cnt;
        for (int n : nums) cnt[n]++;
        vector<vector<int>> res;
        while (!cnt.empty()) {
            vector<int> row;
            for (auto& [k,v] : cnt) row.push_back(k);
            res.push_back(row);
            for (int k : row) if (--cnt[k]==0) cnt.erase(k);
        }
        return res;
    }
};
