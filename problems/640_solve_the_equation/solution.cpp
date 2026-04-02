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
    string solveEquation(string equation) {
        int pos = equation.find('=');
        auto parse = [](string expr) -> pair<int,int> {
            int coef = 0, val = 0, i = 0, n = expr.size();
            while (i < n) {
                int sign = 1;
                if (i < n && (expr[i] == '+' || expr[i] == '-')) {
                    sign = expr[i] == '-' ? -1 : 1;
                    i++;
                }
                int num = 0;
                bool hasNum = false;
                while (i < n && isdigit(expr[i])) {
                    num = num * 10 + (expr[i] - '0');
                    hasNum = true;
                    i++;
                }
                if (i < n && expr[i] == 'x') {
                    coef += sign * (hasNum ? num : 1);
                    i++;
                } else {
                    val += sign * num;
                }
            }
            return {coef, val};
        };
        auto [lc, lv] = parse(equation.substr(0, pos));
        auto [rc, rv] = parse(equation.substr(pos + 1));
        int coef = lc - rc, val = rv - lv;
        if (coef == 0) return val == 0 ? "Infinite solutions" : "No solution";
        return "x=" + to_string(val / coef);
    }
};
