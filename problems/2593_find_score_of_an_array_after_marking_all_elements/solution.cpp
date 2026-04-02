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
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        vector<int> idx(n); iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b){ return nums[a]!=nums[b] ? nums[a]<nums[b] : a<b; });
        vector<bool> marked(n);
        long long score = 0;
        for (int i : idx) {
            if (!marked[i]) {
                score += nums[i]; marked[i]=true;
                if (i>0) marked[i-1]=true;
                if (i<n-1) marked[i+1]=true;
            }
        }
        return score;
    }
};
