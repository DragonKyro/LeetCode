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
    string reformat(string s) {
        string letters, digits;
        for (char c : s) {
            if (isalpha(c)) letters += c;
            else digits += c;
        }
        if (abs((int)letters.size() - (int)digits.size()) > 1) return "";
        if (digits.size() > letters.size()) swap(letters, digits);
        string res;
        for (int i = 0; i < (int)digits.size(); i++) {
            res += letters[i];
            res += digits[i];
        }
        if (letters.size() > digits.size()) res += letters.back();
        return res;
    }
};
