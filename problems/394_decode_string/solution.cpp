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
    string decodeString(string s) {
        stack<pair<string, int>> st;
        string cur;
        int num = 0;
        for (char c : s) {
            if (c == '[') {
                st.push({cur, num});
                cur = "";
                num = 0;
            } else if (c == ']') {
                auto [prev, repeat] = st.top(); st.pop();
                string temp = prev;
                for (int i = 0; i < repeat; i++) temp += cur;
                cur = temp;
            } else if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else {
                cur += c;
            }
        }
        return cur;
    }
};
