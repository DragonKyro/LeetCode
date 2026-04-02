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
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> mp;
        for (int a : nums1) for (int b : nums2) mp[a + b]++;
        int count = 0;
        for (int c : nums3) for (int d : nums4) count += mp[-(c + d)];
        return count;
    }
};
