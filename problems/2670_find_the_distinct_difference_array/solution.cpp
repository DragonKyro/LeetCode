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
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> suf(n+1, 0), ans;
        set<int> s;
        for (int i=n-1;i>=0;i--) { s.insert(nums[i]); suf[i]=s.size(); }
        s.clear();
        for (int i=0;i<n;i++) { s.insert(nums[i]); ans.push_back(s.size()-suf[i+1]); }
        return ans;
    }
};
