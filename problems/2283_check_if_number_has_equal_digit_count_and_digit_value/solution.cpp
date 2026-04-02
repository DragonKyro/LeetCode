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
    bool digitCount(string num) {
        for (int i = 0; i < num.size(); i++) {
            int count = 0;
            for (char c : num) if (c - '0' == i) count++;
            if (count != num[i] - '0') return false;
        }
        return true;
    }
};
