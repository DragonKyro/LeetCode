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
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int notSwap = 0, swap = 1;
        for (int i = 1; i < n; i++) {
            int newNotSwap = INT_MAX, newSwap = INT_MAX;
            if (nums1[i] > nums1[i - 1] && nums2[i] > nums2[i - 1]) {
                newNotSwap = notSwap;
                newSwap = swap + 1;
            }
            if (nums1[i] > nums2[i - 1] && nums2[i] > nums1[i - 1]) {
                newNotSwap = min(newNotSwap, swap);
                newSwap = min(newSwap, notSwap + 1);
            }
            notSwap = newNotSwap;
            swap = newSwap;
        }
        return min(notSwap, swap);
    }
};
