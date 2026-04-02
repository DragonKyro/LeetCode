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
    int minLength(string s) {
        string stack;
        for (char c : s) {
            if (!stack.empty() && ((stack.back()=='A'&&c=='B')||(stack.back()=='C'&&c=='D'))) stack.pop_back();
            else stack.push_back(c);
        }
        return stack.size();
    }
};
