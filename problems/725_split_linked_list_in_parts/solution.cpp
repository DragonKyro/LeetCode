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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = 0;
        ListNode* cur = head;
        while (cur) { len++; cur = cur->next; }
        int width = len / k, extra = len % k;
        vector<ListNode*> result(k, nullptr);
        cur = head;
        for (int i = 0; i < k; i++) {
            result[i] = cur;
            int size = width + (i < extra ? 1 : 0);
            for (int j = 0; j < size - 1; j++) cur = cur->next;
            if (cur) {
                ListNode* next = cur->next;
                cur->next = nullptr;
                cur = next;
            }
        }
        return result;
    }
};
