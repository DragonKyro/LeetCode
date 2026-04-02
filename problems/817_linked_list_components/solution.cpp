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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int count = 0;
        bool inComp = false;
        while (head) {
            if (s.count(head->val)) {
                if (!inComp) { count++; inComp = true; }
            } else inComp = false;
            head = head->next;
        }
        return count;
    }
};
