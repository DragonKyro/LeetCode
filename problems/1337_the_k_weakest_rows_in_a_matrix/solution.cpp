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
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>> strengths;
        for (int i = 0; i < (int)mat.size(); i++)
            strengths.push_back({accumulate(mat[i].begin(), mat[i].end(), 0), i});
        sort(strengths.begin(), strengths.end());
        vector<int> res;
        for (int i = 0; i < k; i++) res.push_back(strengths[i].second);
        return res;
    }
};
