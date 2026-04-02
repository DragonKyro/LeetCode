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
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        string res;
        if ((numerator < 0) ^ (denominator < 0)) res += '-';
        long long num = abs((long long)numerator), den = abs((long long)denominator);
        res += to_string(num / den);
        long long rem = num % den;
        if (rem == 0) return res;
        res += '.';
        unordered_map<long long, int> seen;
        while (rem != 0) {
            if (seen.count(rem)) {
                res.insert(seen[rem], "(");
                res += ')';
                break;
            }
            seen[rem] = res.size();
            rem *= 10;
            res += to_string(rem / den);
            rem %= den;
        }
        return res;
    }
};
