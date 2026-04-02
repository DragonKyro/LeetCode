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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> s(nums.begin(), nums.end());
        ListNode dummy(0, head);
        ListNode* curr = &dummy;
        while (curr->next) {
            if (s.count(curr->next->val)) curr->next = curr->next->next;
            else curr = curr->next;
        }
        return dummy.next;
    }
};
