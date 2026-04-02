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
    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i+1] = prefix[i] + arr[i];
        int ans = 0, minDiff = INT_MAX;
        for (int v = 0; v <= arr.back(); v++) {
            int idx = upper_bound(arr.begin(), arr.end(), v) - arr.begin();
            int total = prefix[idx] + v * (n - idx);
            int diff = abs(total - target);
            if (diff < minDiff) { minDiff = diff; ans = v; }
        }
        return ans;
    }
};
