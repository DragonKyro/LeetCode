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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        unordered_map<int, ListNode*> seen;
        int prefixSum = 0;
        for (ListNode* node = &dummy; node; node = node->next) {
            prefixSum += node->val;
            seen[prefixSum] = node;
        }
        prefixSum = 0;
        for (ListNode* node = &dummy; node; node = node->next) {
            prefixSum += node->val;
            node->next = seen[prefixSum]->next;
        }
        return dummy.next;
    }
};
