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
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());
        unordered_map<int,int> rank;
        for (int i = 0; i < (int)sorted_nums.size(); i++)
            if (rank.find(sorted_nums[i]) == rank.end()) rank[sorted_nums[i]] = i;
        vector<int> res;
        for (int x : nums) res.push_back(rank[x]);
        return res;
    }
};
