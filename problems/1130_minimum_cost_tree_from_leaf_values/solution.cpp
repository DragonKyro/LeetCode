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
    int mctFromLeafValues(vector<int>& arr) {
        int result = 0;
        stack<int> stk;
        stk.push(INT_MAX);
        for (int num : arr) {
            while (stk.top() <= num) {
                int mid = stk.top();
                stk.pop();
                result += mid * min(stk.top(), num);
            }
            stk.push(num);
        }
        while (stk.size() > 2) {
            int top = stk.top();
            stk.pop();
            result += top * stk.top();
        }
        return result;
    }
};
