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
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1, j = num2.size() - 1, carry = 0;
        string result;
        while (i >= 0 || j >= 0 || carry) {
            int x = i >= 0 ? num1[i--] - '0' : 0;
            int y = j >= 0 ? num2[j--] - '0' : 0;
            int sum = x + y + carry;
            result += to_string(sum % 10);
            carry = sum / 10;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
