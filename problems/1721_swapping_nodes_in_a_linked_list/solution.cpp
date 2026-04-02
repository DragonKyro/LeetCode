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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* first = head;
        for (int i = 0; i < k - 1; i++) first = first->next;
        ListNode* node1 = first;
        ListNode* second = head;
        while (first->next) {
            first = first->next;
            second = second->next;
        }
        swap(node1->val, second->val);
        return head;
    }
};
