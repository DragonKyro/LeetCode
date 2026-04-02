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
    string convertToBase7(int num) {
        if (num == 0) return "0";
        bool negative = num < 0;
        num = abs(num);
        string res;
        while (num > 0) {
            res += to_string(num % 7);
            num /= 7;
        }
        if (negative) res += '-';
        reverse(res.begin(), res.end());
        return res;
    }
};
