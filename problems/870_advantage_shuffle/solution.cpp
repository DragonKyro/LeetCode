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
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        sort(nums1.begin(), nums1.end());
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) { return nums2[a] < nums2[b]; });
        vector<int> result(n);
        int lo = 0, hi = n - 1;
        for (int i = n - 1; i >= 0; i--) {
            if (nums1[hi] > nums2[idx[i]]) result[idx[i]] = nums1[hi--];
            else result[idx[i]] = nums1[lo++];
        }
        return result;
    }
};
