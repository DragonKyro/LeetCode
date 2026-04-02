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
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        if (k == 0) { return nums1 == nums2 ? 0 : -1; }
        long long pos = 0, neg = 0;
        for (int i = 0; i < nums1.size(); i++) {
            long long diff = nums1[i] - nums2[i];
            if (diff % k != 0) return -1;
            if (diff > 0) pos += diff / k; else neg += -diff / k;
        }
        return pos == neg ? pos : -1;
    }
};
