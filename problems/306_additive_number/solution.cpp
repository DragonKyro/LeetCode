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
    bool isAdditiveNumber(string num) {
        int n = num.size();
        for (int i = 1; i <= n / 2; i++) {
            for (int j = i + 1; j < n; j++) {
                if (check(num, i, j)) return true;
            }
        }
        return false;
    }
    bool check(string& num, int i, int j) {
        if (num[0] == '0' && i > 1) return false;
        if (num[i] == '0' && j - i > 1) return false;
        string a = num.substr(0, i), b = num.substr(i, j - i);
        int k = j;
        while (k < num.size()) {
            string c = addStrings(a, b);
            if (num.compare(k, c.size(), c) != 0) return false;
            k += c.size();
            a = b;
            b = c;
        }
        return k == num.size();
    }
    string addStrings(string& a, string& b) {
        string res;
        int carry = 0, i = a.size() - 1, j = b.size() - 1;
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';
            res += (char)('0' + sum % 10);
            carry = sum / 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
