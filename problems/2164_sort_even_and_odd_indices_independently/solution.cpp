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
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> even, odd;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (i % 2 == 0) even.push_back(nums[i]);
            else odd.push_back(nums[i]);
        }
        sort(even.begin(), even.end());
        sort(odd.rbegin(), odd.rend());
        int ei = 0, oi = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            nums[i] = (i % 2 == 0) ? even[ei++] : odd[oi++];
        }
        return nums;
    }
};
