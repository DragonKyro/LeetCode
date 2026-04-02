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
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> res = prices;
        stack<int> st;
        for (int i = 0; i < (int)prices.size(); i++) {
            while (!st.empty() && prices[st.top()] >= prices[i]) {
                res[st.top()] -= prices[i];
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};
