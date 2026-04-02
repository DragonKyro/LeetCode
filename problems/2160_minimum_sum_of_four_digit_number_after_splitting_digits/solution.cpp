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
    int minimumSum(int num) {
        vector<int> digits;
        while (num > 0) { digits.push_back(num % 10); num /= 10; }
        sort(digits.begin(), digits.end());
        return (digits[0] * 10 + digits[2]) + (digits[1] * 10 + digits[3]);
    }
};
