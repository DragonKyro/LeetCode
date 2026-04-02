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
    int secondHighest(string s) {
        set<int> digits;
        for (char c : s) {
            if (isdigit(c)) digits.insert(c - '0');
        }
        if (digits.size() < 2) return -1;
        auto it = digits.end();
        --it; --it;
        return *it;
    }
};
