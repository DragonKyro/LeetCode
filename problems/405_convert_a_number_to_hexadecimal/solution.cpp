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
    string toHex(int num) {
        if (num == 0) return "0";
        unsigned int n = num;
        string hex = "0123456789abcdef";
        string result;
        while (n) {
            result = hex[n & 0xf] + result;
            n >>= 4;
        }
        return result;
    }
};
