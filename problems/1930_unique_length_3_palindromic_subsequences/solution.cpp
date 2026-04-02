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
    int countPalindromicSubsequence(string s) {
        int result = 0;
        for (char c = 'a'; c <= 'z'; c++) {
            int first = s.find(c), last = s.rfind(c);
            if (first != string::npos && last - first > 1) {
                unordered_set<char> st(s.begin() + first + 1, s.begin() + last);
                result += st.size();
            }
        }
        return result;
    }
};
