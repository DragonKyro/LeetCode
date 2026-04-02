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
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        unordered_map<long long, long long> cnt;
        for (int b : nums2) cnt[(long long)b * k]++;
        long long res = 0;
        for (int a : nums1) {
            for (long long d = 1; d * d <= a; d++) {
                if (a % d == 0) {
                    if (cnt.count(d)) res += cnt[d];
                    if (d != a/d && cnt.count(a/d)) res += cnt[a/d];
                }
            }
        }
        return res;
    }
};
