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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* prev = list1;
        for (int i = 0; i < a - 1; i++) prev = prev->next;
        ListNode* end = prev;
        for (int i = 0; i < b - a + 2; i++) end = end->next;
        prev->next = list2;
        ListNode* tail = list2;
        while (tail->next) tail = tail->next;
        tail->next = end;
        return list1;
    }
};
