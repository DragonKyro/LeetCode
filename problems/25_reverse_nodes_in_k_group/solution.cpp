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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0, head);
        ListNode* prev = &dummy;
        while (true) {
            ListNode* kth = prev;
            for (int i = 0; i < k; i++) {
                kth = kth->next;
                if (!kth) return dummy.next;
            }
            ListNode* curr = prev->next;
            for (int i = 0; i < k - 1; i++) {
                ListNode* tmp = curr->next;
                curr->next = tmp->next;
                tmp->next = prev->next;
                prev->next = tmp;
            }
            prev = curr;
        }
        return dummy.next;
    }
};
