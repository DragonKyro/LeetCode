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
    string removeKdigits(string num, int k) {
        string stack;
        for (char c : num) {
            while (k && !stack.empty() && stack.back() > c) {
                stack.pop_back();
                k--;
            }
            stack.push_back(c);
        }
        while (k--) stack.pop_back();
        int start = 0;
        while (start < stack.size() && stack[start] == '0') start++;
        string result = stack.substr(start);
        return result.empty() ? "0" : result;
    }
};
