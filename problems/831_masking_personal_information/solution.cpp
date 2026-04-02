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
    string maskPII(string s) {
        if (s.find('@') != string::npos) {
            transform(s.begin(), s.end(), s.begin(), ::tolower);
            int at = s.find('@');
            return s[0] + string("*****") + s.substr(at - 1);
        }
        string digits;
        for (char c : s) if (isdigit(c)) digits += c;
        string local = "***-***-" + digits.substr(digits.size() - 4);
        if (digits.size() == 10) return local;
        return "+" + string(digits.size() - 10, '*') + "-" + local;
    }
};
