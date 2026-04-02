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
    string maxValue(string n, int x) {
        bool isNeg = n[0] == '-';
        int start = isNeg ? 1 : 0;
        for (int i = start; i < n.size(); i++) {
            int digit = n[i] - '0';
            if (isNeg && digit > x) return n.substr(0, i) + char('0' + x) + n.substr(i);
            if (!isNeg && digit < x) return n.substr(0, i) + char('0' + x) + n.substr(i);
        }
        return n + char('0' + x);
    }
};
