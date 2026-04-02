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
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> visited(n, false);
        stack<int> st;
        st.push(start);
        while (!st.empty()) {
            int i = st.top(); st.pop();
            if (arr[i] == 0) return true;
            if (visited[i]) continue;
            visited[i] = true;
            if (i + arr[i] < n) st.push(i + arr[i]);
            if (i - arr[i] >= 0) st.push(i - arr[i]);
        }
        return false;
    }
};
