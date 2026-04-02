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
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int n = matrix[0].size(), maxArea = 0;
        vector<int> heights(n, 0);
        for (auto& row : matrix) {
            for (int j = 0; j < n; j++) heights[j] = row[j] == '1' ? heights[j] + 1 : 0;
            stack<int> st;
            for (int i = 0; i <= n; i++) {
                int h = (i == n) ? 0 : heights[i];
                while (!st.empty() && heights[st.top()] > h) {
                    int height = heights[st.top()]; st.pop();
                    int width = st.empty() ? i : i - st.top() - 1;
                    maxArea = max(maxArea, height * width);
                }
                st.push(i);
            }
        }
        return maxArea;
    }
};
