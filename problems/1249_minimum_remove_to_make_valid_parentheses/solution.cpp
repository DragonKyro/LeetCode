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
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == '(') st.push(i);
            else if (s[i] == ')') {
                if (!st.empty()) st.pop();
                else s[i] = '*';
            }
        }
        while (!st.empty()) { s[st.top()] = '*'; st.pop(); }
        string res;
        for (char c : s) if (c != '*') res += c;
        return res;
    }
};
