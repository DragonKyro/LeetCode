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
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double tax = 0;
        int prev = 0;
        for (auto& b : brackets) {
            int taxable = min(income, b[0]) - prev;
            if (taxable <= 0) break;
            tax += taxable * b[1] / 100.0;
            prev = b[0];
        }
        return tax;
    }
};
