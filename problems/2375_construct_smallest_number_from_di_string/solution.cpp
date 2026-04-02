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
    string smallestNumber(string pattern) {
        string result;
        stack<char> st;
        for (int i = 0; i <= pattern.size(); i++) {
            st.push('1' + i);
            if (i == pattern.size() || pattern[i] == 'I') {
                while (!st.empty()) { result += st.top(); st.pop(); }
            }
        }
        return result;
    }
};
