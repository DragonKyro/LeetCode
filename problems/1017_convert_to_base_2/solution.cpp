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
    string baseNeg2(int n) {
        if (n == 0) return "0";
        string result;
        while (n != 0) {
            int remainder = n % (-2);
            n /= -2;
            if (remainder < 0) { remainder += 2; n += 1; }
            result = to_string(remainder) + result;
        }
        return result;
    }
};
