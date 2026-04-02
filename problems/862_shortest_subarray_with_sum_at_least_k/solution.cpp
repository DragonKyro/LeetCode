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
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + nums[i];
        int result = n + 1;
        deque<int> dq;
        for (int i = 0; i <= n; i++) {
            while (!dq.empty() && prefix[i] - prefix[dq.front()] >= k)
                result = min(result, i - dq.front()), dq.pop_front();
            while (!dq.empty() && prefix[i] <= prefix[dq.back()])
                dq.pop_back();
            dq.push_back(i);
        }
        return result <= n ? result : -1;
    }
};
