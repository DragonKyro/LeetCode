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
    bool isValid(string s) {
        string stack;
        for (char c : s) {
            stack.push_back(c);
            int n = stack.size();
            if (n >= 3 && stack.substr(n - 3) == "abc")
                stack.erase(n - 3);
        }
        return stack.empty();
    }
};
