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
    NestedInteger deserialize(string s) {
        if (s[0] != '[') return NestedInteger(stoi(s));
        stack<NestedInteger> st;
        int start = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '[') {
                st.push(NestedInteger());
                start = i + 1;
            } else if (s[i] == ',' || s[i] == ']') {
                if (i > start) {
                    st.top().add(NestedInteger(stoi(s.substr(start, i - start))));
                }
                start = i + 1;
                if (s[i] == ']' && st.size() > 1) {
                    NestedInteger top = st.top(); st.pop();
                    st.top().add(top);
                }
            }
        }
        return st.top();
    }
};
