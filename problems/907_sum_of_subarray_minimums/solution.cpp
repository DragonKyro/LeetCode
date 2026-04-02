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
    int sumSubarrayMins(vector<int>& arr) {
        int MOD = 1e9 + 7, n = arr.size();
        vector<int> left(n), right(n);
        stack<pair<int,int>> st;
        for (int i = 0; i < n; i++) {
            int count = 1;
            while (!st.empty() && st.top().first >= arr[i]) {
                count += st.top().second; st.pop();
            }
            left[i] = count;
            st.push({arr[i], count});
        }
        while (!st.empty()) st.pop();
        for (int i = n - 1; i >= 0; i--) {
            int count = 1;
            while (!st.empty() && st.top().first > arr[i]) {
                count += st.top().second; st.pop();
            }
            right[i] = count;
            st.push({arr[i], count});
        }
        long long result = 0;
        for (int i = 0; i < n; i++)
            result = (result + (long long)arr[i] * left[i] * right[i]) % MOD;
        return result;
    }
};
