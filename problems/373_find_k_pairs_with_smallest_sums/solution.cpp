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
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        auto cmp = [&](pair<int,int>& a, pair<int,int>& b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < min(k, (int)nums1.size()); i++)
            pq.push({i, 0});
        while (!pq.empty() && (int)res.size() < k) {
            auto [i, j] = pq.top(); pq.pop();
            res.push_back({nums1[i], nums2[j]});
            if (j + 1 < (int)nums2.size()) pq.push({i, j + 1});
        }
        return res;
    }
};
