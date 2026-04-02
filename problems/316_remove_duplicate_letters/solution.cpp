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
    string removeDuplicateLetters(string s) {
        int last[26] = {};
        for (int i = 0; i < s.size(); i++) last[s[i] - 'a'] = i;
        bool seen[26] = {};
        string stack;
        for (int i = 0; i < s.size(); i++) {
            if (seen[s[i] - 'a']) continue;
            while (!stack.empty() && s[i] < stack.back() && last[stack.back() - 'a'] > i) {
                seen[stack.back() - 'a'] = false;
                stack.pop_back();
            }
            stack += s[i];
            seen[s[i] - 'a'] = true;
        }
        return stack;
    }
};
