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
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());
        int left = (n - 1) / 2, right = n - 1;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) nums[i] = sorted[left--];
            else nums[i] = sorted[right--];
        }
    }
};
