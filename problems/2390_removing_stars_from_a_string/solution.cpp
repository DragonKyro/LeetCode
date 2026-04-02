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
    string removeStars(string s) {
        string stack;
        for (char c : s) {
            if (c == '*') stack.pop_back();
            else stack.push_back(c);
        }
        return stack;
    }
};
