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
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (int n : nums) count[n]++;
        vector<vector<int>> bucket(nums.size() + 1);
        for (auto& [num, freq] : count) bucket[freq].push_back(num);
        vector<int> res;
        for (int i = bucket.size() - 1; i >= 0 && (int)res.size() < k; i--)
            for (int n : bucket[i]) { res.push_back(n); if ((int)res.size() == k) break; }
        return res;
    }
};
