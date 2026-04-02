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
    int medianOfUniquenessArray(vector<int>& nums) {
        int n = nums.size();
        long long total = (long long)n * (n + 1) / 2;
        auto atMost = [&](int k) -> long long {
            long long cnt = 0;
            unordered_map<int,int> freq;
            int l = 0;
            for (int r = 0; r < n; r++) {
                freq[nums[r]]++;
                while ((int)freq.size() > k) {
                    if (--freq[nums[l]] == 0) freq.erase(nums[l]);
                    l++;
                }
                cnt += r - l + 1;
            }
            return cnt;
        };
        int lo = 1, hi = n;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (atMost(mid) >= (total + 1) / 2) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};
