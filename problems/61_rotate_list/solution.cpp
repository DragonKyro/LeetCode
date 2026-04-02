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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        int length = 1;
        ListNode* tail = head;
        while (tail->next) { tail = tail->next; length++; }
        k %= length;
        if (k == 0) return head;
        tail->next = head;
        int steps = length - k;
        ListNode* curr = head;
        for (int i = 0; i < steps - 1; i++) curr = curr->next;
        ListNode* newHead = curr->next;
        curr->next = nullptr;
        return newHead;
    }
};
