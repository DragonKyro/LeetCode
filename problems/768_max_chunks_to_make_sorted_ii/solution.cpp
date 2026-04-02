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
    int maxChunksToSorted(vector<int>& arr) {
        stack<int> stk;
        for (int num : arr) {
            int mx = num;
            while (!stk.empty() && stk.top() > num) {
                mx = max(mx, stk.top()); stk.pop();
            }
            stk.push(mx);
        }
        return stk.size();
    }
};
