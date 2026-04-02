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
    string reformatNumber(string number) {
        string digits;
        for (char c : number) if (isdigit(c)) digits += c;
        string result;
        int i = 0;
        while ((int)digits.size() - i > 4) {
            if (!result.empty()) result += '-';
            result += digits.substr(i, 3);
            i += 3;
        }
        int remaining = digits.size() - i;
        if (remaining <= 3) {
            if (!result.empty()) result += '-';
            result += digits.substr(i);
        } else {
            if (!result.empty()) result += '-';
            result += digits.substr(i, 2) + '-' + digits.substr(i + 2);
        }
        return result;
    }
};
