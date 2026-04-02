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
    int pairSum(ListNode* head) {
        vector<int> values;
        ListNode* curr = head;
        while (curr) { values.push_back(curr->val); curr = curr->next; }
        int n = values.size(), maxSum = 0;
        for (int i = 0; i < n / 2; i++) {
            maxSum = max(maxSum, values[i] + values[n - 1 - i]);
        }
        return maxSum;
    }
};
