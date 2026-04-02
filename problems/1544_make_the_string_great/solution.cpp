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
    string makeGood(string s) {
        string stack;
        for (char c : s) {
            if (!stack.empty() && stack.back() != c && tolower(stack.back()) == tolower(c)) {
                stack.pop_back();
            } else {
                stack += c;
            }
        }
        return stack;
    }
};
