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
    int maxSumMinProduct(vector<int>& nums) {
        long long MOD = 1e9 + 7;
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + nums[i];
        vector<int> left(n, -1), right(n, n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] >= nums[i]) { right[st.top()] = i; st.pop(); }
            if (!st.empty()) left[i] = st.top();
            st.push(i);
        }
        long long result = 0;
        for (int i = 0; i < n; i++) {
            long long total = prefix[right[i]] - prefix[left[i] + 1];
            result = max(result, (long long)nums[i] * total);
        }
        return result % MOD;
    }
};
