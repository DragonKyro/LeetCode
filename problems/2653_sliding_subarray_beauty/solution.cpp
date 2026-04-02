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
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int cnt[101] = {}, n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            cnt[nums[i]+50]++;
            if (i >= k) cnt[nums[i-k]+50]--;
            if (i >= k-1) {
                int c = 0;
                for (int j = 0; j < 101; j++) {
                    c += cnt[j];
                    if (c >= x) { ans.push_back(j-50 < 0 ? j-50 : 0); break; }
                }
            }
        }
        return ans;
    }
};
