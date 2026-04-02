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
    int getDecimalValue(ListNode* head) {
        int val = 0;
        while (head) {
            val = val * 2 + head->val;
            head = head->next;
        }
        return val;
    }
};
