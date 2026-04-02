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
    int balancedStringSplit(string s) {
        int res = 0, balance = 0;
        for (char c : s) {
            balance += c == 'L' ? 1 : -1;
            if (balance == 0) res++;
        }
        return res;
    }
};
