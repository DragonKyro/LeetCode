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
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<int> idx(n); iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b){ return nums2[a] > nums2[b]; });
        priority_queue<int, vector<int>, greater<>> pq;
        long long s = 0, ans = 0;
        for (int i : idx) {
            pq.push(nums1[i]); s += nums1[i];
            if ((int)pq.size() > k) { s -= pq.top(); pq.pop(); }
            if ((int)pq.size() == k) ans = max(ans, s * nums2[i]);
        }
        return ans;
    }
};
