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
    ListNode* partition(ListNode* head, int x) {
        ListNode beforeHead(0), afterHead(0);
        ListNode* before = &beforeHead;
        ListNode* after = &afterHead;
        while (head) {
            if (head->val < x) { before->next = head; before = before->next; }
            else { after->next = head; after = after->next; }
            head = head->next;
        }
        after->next = nullptr;
        before->next = afterHead.next;
        return beforeHead.next;
    }
};
