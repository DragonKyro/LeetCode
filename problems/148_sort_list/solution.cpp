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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *slow = head, *fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow->next;
        slow->next = nullptr;
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);
        ListNode dummy(0);
        ListNode* curr = &dummy;
        while (left && right) {
            if (left->val <= right->val) { curr->next = left; left = left->next; }
            else { curr->next = right; right = right->next; }
            curr = curr->next;
        }
        curr->next = left ? left : right;
        return dummy.next;
    }
};
