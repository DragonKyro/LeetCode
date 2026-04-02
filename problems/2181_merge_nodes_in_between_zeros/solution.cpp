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
    ListNode* mergeNodes(ListNode* head) {
        ListNode dummy(0);
        ListNode* curr = &dummy;
        ListNode* node = head->next;
        int total = 0;
        while (node) {
            if (node->val == 0) {
                curr->next = new ListNode(total);
                curr = curr->next;
                total = 0;
            } else {
                total += node->val;
            }
            node = node->next;
        }
        return dummy.next;
    }
};
