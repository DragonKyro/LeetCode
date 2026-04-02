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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> vals;
        while (head) { vals.push_back(head->val); head = head->next; }
        vector<int> ans(vals.size(), 0);
        stack<int> st;
        for (int i = 0; i < vals.size(); i++) {
            while (!st.empty() && vals[st.top()] < vals[i]) {
                ans[st.top()] = vals[i]; st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};
