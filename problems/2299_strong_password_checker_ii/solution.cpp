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
    bool strongPasswordCheckerII(string password) {
        if (password.size() < 8) return false;
        bool lower = false, upper = false, digit = false, special = false;
        string sp = "!@#$%^&*()-+";
        for (int i = 0; i < password.size(); i++) {
            char c = password[i];
            if (islower(c)) lower = true;
            if (isupper(c)) upper = true;
            if (isdigit(c)) digit = true;
            if (sp.find(c) != string::npos) special = true;
            if (i > 0 && c == password[i-1]) return false;
        }
        return lower && upper && digit && special;
    }
};
