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
    string fractionAddition(string expression) {
        long long num = 0, den = 1;
        istringstream ss(expression);
        long long n, d;
        char slash;
        while (ss >> n >> slash >> d) {
            num = num * d + n * den;
            den *= d;
            long long g = __gcd(abs(num), abs(den));
            num /= g; den /= g;
        }
        if (den < 0) { num = -num; den = -den; }
        return to_string(num) + "/" + to_string(den);
    }
};
