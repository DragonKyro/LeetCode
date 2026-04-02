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
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> mp;
        for (int num : nums2) {
            while (!st.empty() && st.top() < num) { mp[st.top()] = num; st.pop(); }
            st.push(num);
        }
        vector<int> result;
        for (int num : nums1) result.push_back(mp.count(num) ? mp[num] : -1);
        return result;
    }
};
